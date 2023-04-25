#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
        wxImage imagebanan;
		imagebanan.AddHandler(new wxPNGHandler);
		imagebanan.LoadFile("banan.png", wxBITMAP_TYPE_PNG);
		bananbitmap = wxBitmap(imagebanan);
}

void GUIMyFrame1::m_button_save_click( wxCommandEvent& event )
{
    wxFileDialog zapisDialog(this, _("Wybierz rozszerzenie"), _(""), _(""), _("Pliki .png |*.png;| Pliki .bmp |*.bmp;| Piliki.jpg |*.jpg;| Pliki .jpeg|*.jpeg"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (zapisDialog.ShowModal() == wxID_CANCEL) return;
	wxImage zapis_obrazka = bitmap.ConvertToImage();
	zapis_obrazka.AddHandler(new wxJPEGHandler);
	zapis_obrazka.AddHandler(new wxBMPHandler);
	zapis_obrazka.AddHandler(new wxPNGHandler);
	zapis_obrazka.SaveFile(zapisDialog.GetPath());
    draw_things();
}

void GUIMyFrame1::m_checkBox_banan_check( wxCommandEvent& event )
{
    m_slider_position->Enable(m_checkBox_banan->IsChecked());
    draw_things();
}

void GUIMyFrame1::m_slider_position_onscroll( wxScrollEvent& event )
{
    m_gauge_position->SetValue(event.GetPosition());
	draw_things();
}

void GUIMyFrame1::m_button_color_click( wxCommandEvent& event )
{
    wxColourDialog kolorDialog(this, nullptr);
	if (kolorDialog.ShowModal() == wxID_CANCEL) return;
    kolor = kolorDialog.GetColourData().GetColour();
    draw_things();
}

void GUIMyFrame1::m_choice_star_onchoice( wxCommandEvent& event )
{
    draw_things();
    event.Skip();
}

void GUIMyFrame1::draw_things() 
{
    //bitmapa - cale okno
    std::unique_ptr<wxClientDC> clientDC(new wxClientDC(this));
    bitmap = wxBitmap(this->GetSize());
    std::unique_ptr<wxBufferedDC> buffer(new wxBufferedDC(clientDC.get(), bitmap));
    buffer->SetDeviceOrigin(this->GetSize().x / 2.5, this->GetSize().y / 2);
    buffer->SetBackground(*wxWHITE);
    buffer->Clear();

    //banan 
    double bananaFactor = 0.1 * m_gauge_position->GetValue();
    if (m_checkBox_banan->IsChecked())
        buffer->DrawBitmap(bananbitmap, wxPoint( -50 - bananaFactor - bananbitmap.GetWidth()/1.5, 40 - m_gauge_position->GetValue() - bananbitmap.GetWidth()/1.5), true);

    //czlowiek
    buffer->DrawLine(wxPoint(0,-10), wxPoint(0,90)); // brzuch
    buffer->DrawLine(wxPoint(0, 0), wxPoint(-50 - bananaFactor, 40 - m_gauge_position->GetValue())); //lewa reka 
    buffer->DrawLine(wxPoint(0, 0), wxPoint(40, 40)); // prawa reka
    buffer->DrawLine(wxPoint(0, 90), wxPoint(-40, 130)); // lewa noga
    buffer->DrawLine(wxPoint(0, 90), wxPoint(30, 130)); // prawa noga
    buffer->DrawCircle(wxPoint(0, -30), wxCoord(20)); //glowa
    buffer->DrawEllipse(wxCoord(-15), wxCoord(-35), wxCoord(9), wxCoord(8)); //lewe oko
    buffer->DrawEllipse(wxCoord(5), wxCoord(-35), wxCoord(9), wxCoord(8)); //prawe oko  
    if (m_checkBox_banan->IsChecked()) //usmiech w zaleznosci od banana
    {
        buffer->DrawEllipticArc(wxPoint(-12, -20), wxSize(20, 5), 180, 360);
    } else
    {
        buffer->DrawEllipticArc(wxPoint(-12, -20), wxSize(20, 5), 0, 180);
    }

    //Napisy
    buffer->SetBrush(wxBrush(kolor));
    buffer->DrawText(m_text->GetValue(), wxPoint(-150, 100));
    wxString textRotated(m_text->GetValue());
    buffer->SetBrush(wxBrush(kolor));
    buffer->SetPen(wxPen(kolor));
    buffer->SetFont(wxFont(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, ""));
    buffer->DrawRotatedText(m_text->GetValue(), wxPoint(60, 50), 90);
    
    //Gwiazdka itd
    buffer->SetPen(wxPen(*wxLIGHT_GREY));
    if(m_choice_star->GetString(m_choice_star->GetSelection())=="gwiazdka") 
    {
        //gwiazdka
        wxPoint starr[5] = {wxPoint(-110, -100), wxPoint(-40, -20), wxPoint(-180, -60), wxPoint(-40, -60), wxPoint(-180, -20)};
        buffer->SetBrush(wxBrush(kolor));
        buffer->DrawPolygon(5, starr);
    }
    else if(m_choice_star->GetString(m_choice_star->GetSelection())=="slonce") 
    {
        //slonce
        buffer->SetBrush(wxBrush(*wxYELLOW));
        buffer->DrawCircle(wxPoint(-100, -60), wxCoord(40));
    }    
    else if(m_choice_star->GetString(m_choice_star->GetSelection())=="ksiezyc") 
    {
        //ksiezyc
        buffer->SetBrush(wxBrush(*wxGREY_BRUSH));
        buffer->DrawCircle(wxPoint(-100, -60), wxCoord(40));
        buffer->SetBrush(wxBrush(*wxWHITE));
        buffer->DrawCircle(wxPoint(-120, -80), wxCoord(40));
        buffer->SetBrush(wxBrush(*wxBLACK));
        buffer->DrawCircle(wxPoint(-80, -70), wxCoord(5));
        buffer->SetBrush(wxBrush(*wxBLACK));
        buffer->DrawLine(wxPoint(-100, -50), wxPoint(-80, -50));
    }
    Refresh(true);
}
