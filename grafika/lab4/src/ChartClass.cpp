#include <wx/dc.h>
#include <memory>

#include "ChartClass.h"
#include "vecmat.h"

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c)
{
	cfg = std::move(c);
	x_step = 200;
}

void ChartClass::Set_Range()
{
	double xmin = 9999.9, xmax = -9999.9, ymin = 9999.9, ymax = -9999.9;
	double x, y, step;
	int i;

	xmin = cfg->Get_x_start();
	xmax = cfg->Get_x_stop();

	step = (cfg->Get_x_stop() - cfg->Get_x_start()) / x_step;
	x = cfg->Get_x_start();

	for (i = 0; i <= x_step; i++)
	{
		y = GetFunctionValue(x);
		if (y > ymax)
			ymax = y;
		if (y < ymin)
			ymin = y;
		x = x + step;
	}

	y_min = ymin;
	y_max = ymax;
	x_min = xmin;
	x_max = xmax;
}

double ChartClass::GetFunctionValue(double x)
{
	if (cfg->Get_F_type() == 1)
		return x * x;
	if (cfg->Get_F_type() == 2)
		return 0.5 * exp(4 * x - 3 * x * x);
	return x + sin(x * 4.0);
}

void ChartClass::Draw(wxDC *dc, int w, int h)
{
	dc->SetBackground(wxBrush(wxColor(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(wxColor(255, 0, 0)));
	dc->DrawRectangle(10, 10, w - 20, h - 20);
	dc->SetClippingRegion(wxRect(10, 10, w - 20, h - 20));
	Set_Range();

	const double x0 = cfg->Get_x0(); 
	const double x1 = cfg->Get_x1();
	const double y0 = cfg->Get_y0();
	const double y1 = cfg->Get_y1();
	const double x_start = cfg->Get_x_start(); 
	const double x_stop = cfg->Get_x_stop();
	const double delta_x = cfg->Get_dX(); 
	const double delta_y = cfg->Get_dY(); 
	const double dx = (x_max - x_min) / x_step;
	const double alpha = cfg->Get_Alpha();
	Matrix t;
	t.data[0][0] = 1;
	t.data[0][1] = 0;
	t.data[0][2] = 0;
	t.data[1][0] = 0;
	t.data[1][1] = 1;
	t.data[1][2] = 0;
	t.data[2][0] = 0;
	t.data[2][1] = 0;
	t.data[2][2] = 1;

	if (cfg->RotateScreenCenter())
	{
		t = Set_translation(w/2, h/2) * Set_rotation(0-alpha) * Set_translation(delta_x, delta_y) * Set_scale(w - 20, h - 20, x0, x1, y0, y1); 
	}
	else
	{
		t = Set_translation(w/2, h/2) * Set_translation(delta_x, delta_y) *	Set_rotation(0-alpha) * Set_scale(w - 20, h - 20, x0, x1, y0, y1); 
	}

	dc->SetPen(wxPen(wxColor(0, 255, 0)));
	double x_step_len = (x_max - x_min) / x_step;
	for (double x = x_min; x < x_max; x += x_step_len)
		line2d(dc, t, x, GetFunctionValue(x), x + x_step_len, GetFunctionValue(x + x_step_len));

	dc->SetPen(wxPen(wxColor(0, 0, 255)));
	if (x0 <= 0 && x1 >= 0)
	{
		line2d(dc, t, 0, y_min, 0, y_max); 
		drawText(dc, t, alpha, 0.1, y_max, y_max); 
		drawText(dc, t, alpha, 0.1, y_max/2, y_max/2);
		drawText(dc, t, alpha, 0.1, y_min, y_min);
		drawText(dc, t, alpha, 0.1, y_min/2, y_min/2);
		line2d(dc, t, -0.05, y_max, 0.05, y_max); 
		line2d(dc, t, -0.02, y_max/2, 0.02, y_max/2);
		line2d(dc, t, -0.05, y_min, 0.05, y_min);
		line2d(dc, t, -0.02, y_min/2, 0.02, y_min/2);
	}
	if (y0 <= 0 && y1 >= 0)
	{
		line2d(dc, t, x_start, 0, x_stop, 0); 
		drawText(dc, t, alpha, x_stop, 0, x_stop); 
		drawText(dc, t, alpha, x_stop/2, 0, x_stop/2);
		drawText(dc, t, alpha, x_start, 0, x_start);
		drawText(dc, t, alpha, x_start / 2, 0, x_start / 2);
		line2d(dc, t, x_stop, -0.05, x_stop, 0.05); 
		line2d(dc, t, x_stop/2, -0.02, x_stop/2, 0.02);
		line2d(dc, t, x_start, -0.05, x_start, 0.05);
		line2d(dc, t, x_start/2, -0.02, x_start/2, 0.02);
	}
}

void ChartClass::line2d(wxDC *dc, Matrix t, double x1, double y1, double x2, double y2)
{
	Vector cords1;
	cords1.Set(x1, y1);
	Vector cords1_prim = t*cords1;
	double x1_changed = cords1_prim.GetX();
	double y1_changed = cords1_prim.GetY();

	Vector cords2;
	cords2.Set(x2, y2);
	Vector cords2_prim = t*cords2;
	double x2_changed = cords2_prim.GetX();
	double y2_changed = cords2_prim.GetY();

	dc->DrawLine(x1_changed, y1_changed, x2_changed, y2_changed);
}

Matrix ChartClass::Set_scale(double w, double h, double x0, double x1, double y0, double y1)
{
	Matrix coverted;
	double scale_x = w/(x1-x0);
	double scale_y = -h/(y1-y0);
	coverted.data[0][1] = 0;
	coverted.data[0][2] = 0;
	coverted.data[1][0] = 0;
	coverted.data[0][0] = scale_x; 
	coverted.data[1][1] = scale_y;
	coverted.data[1][2] = 0;
	coverted.data[2][0] = 0;
	coverted.data[2][1] = 0;
	coverted.data[2][2] = 1;
	return coverted;
}

Matrix ChartClass::Set_translation(double x, double y)
{
	Matrix coverted;
	coverted.data[0][0] = 1;
	coverted.data[0][1] = 0;
	coverted.data[0][2] = x; 
	coverted.data[1][0] = 0;
	coverted.data[1][1] = 1;
	coverted.data[1][2] = y;
	coverted.data[2][0] = 0;
	coverted.data[2][1] = 0;
	coverted.data[2][2] = 1;
	return coverted;
}

Matrix ChartClass::Set_rotation(double alpha)
{
	Matrix coverted;
	double alpha_rad = alpha*M_PI/180.0; 
	coverted.data[0][0] = cos(alpha_rad); 
	coverted.data[0][1] = -sin(alpha_rad);
	coverted.data[0][2] = 0;
	coverted.data[1][0] = sin(alpha_rad);
	coverted.data[1][1] = cos(alpha_rad);
	coverted.data[1][2] = 0;
	coverted.data[2][0] = 0;
	coverted.data[2][1] = 0;
	coverted.data[2][2] = 1;
	return coverted;
}

void ChartClass::drawText(wxDC *dc, Matrix t, double alpha, double x, double y, double value)
{
	Vector txt;
	txt.Set(x, y);
	txt = t*txt;
	dc->DrawRotatedText(wxString::Format(wxT("%.2f"), value), txt.GetX(), txt.GetY(), alpha);
}

double ChartClass::Get_Y_min()
{
	Set_Range();
	return y_min;
}

double ChartClass::Get_Y_max()
{
	Set_Range();
	return y_max;
}

