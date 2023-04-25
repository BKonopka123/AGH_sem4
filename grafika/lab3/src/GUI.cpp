///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	//m_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DFACE ) );

	bSizer2->Add( m_panel, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_button_save = new wxButton( this, wxID_ANY, wxT("Zapis do pliku"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button_save, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_checkBox_banan = new wxCheckBox( this, wxID_ANY, wxT("banan"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_checkBox_banan, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_slider_position = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( -1,-1 ), wxSL_HORIZONTAL );
	m_slider_position->SetLineSize(1000);
	m_slider_position->Enable(m_checkBox_banan->IsChecked());
	bSizer3->Add( m_slider_position, 0, wxEXPAND|wxALL, 5 );

	m_gauge_position = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	m_gauge_position->SetValue( 0 );
	bSizer3->Add( m_gauge_position, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_button_color = new wxButton( this, wxID_ANY, wxT("Kolor gwiazdki"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button_color, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_text = new wxTextCtrl( this, wxID_ANY, wxT("tekst"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_text, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	wxString m_choice_starChoices[] = { wxT("gwiazdka"), wxT("slonce"), wxT("ksiezyc") };
	int m_choice_starNChoices = sizeof( m_choice_starChoices ) / sizeof( wxString );
	m_choice_star = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_starNChoices, m_choice_starChoices, 0 );
	m_choice_star->SetSelection( 0 );
	bSizer3->Add( m_choice_star, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::MyFrame1_OnPaint ) );
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::MyFrame1_OnUpdateUI ) );
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_save_click ), NULL, this );
	m_checkBox_banan->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::m_checkBox_banan_check ), NULL, this );
	m_slider_position->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_button_color->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_color_click ), NULL, this );
	m_choice_star->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::m_choice_star_onchoice ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::MyFrame1_OnPaint ) );
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::MyFrame1_OnUpdateUI ) );
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_save_click ), NULL, this );
	m_checkBox_banan->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::m_checkBox_banan_check ), NULL, this );
	m_slider_position->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_slider_position->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_slider_position_onscroll ), NULL, this );
	m_button_color->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_color_click ), NULL, this );
	m_choice_star->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::m_choice_star_onchoice ), NULL, this );

}
