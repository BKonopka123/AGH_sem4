///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <memory>


///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel;
		wxButton* m_button_save;
		wxCheckBox* m_checkBox_banan;
		wxSlider* m_slider_position;
		wxGauge* m_gauge_position;
		wxButton* m_button_color;
		wxTextCtrl* m_text;
		wxChoice* m_choice_star;

		// Virtual event handlers, override them in your derived class
		virtual void m_button_save_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox_banan_check( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_slider_position_onscroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_button_color_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choice_star_onchoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void MyFrame1_OnPaint(wxPaintEvent& event) { event.Skip(); }
		virtual void MyFrame1_OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GFK lab03 Konopka Bartosz"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 549,425 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

