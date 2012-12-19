// generated by Fast Light User Interface Designer (fluid) version 1.0109

#ifndef appsaudit_h
#define appsaudit_h
#include <FL/Fl.H>
void options_callback(Fl_Widget *, void* userdata);
void depends_callback(Fl_Widget *, void* userdata);
void brw_extn_callback(Fl_Widget *, void *);
void brw_results_callback(Fl_Widget *, void *);
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
extern void depends_callback(Fl_Menu_*, void*);
extern void options_callback(Fl_Menu_*, void*);
#include <FL/Fl_Box.H>
extern Fl_Box *box_extensions;
extern Fl_Box *box_results;
#include <FL/Fl_Browser.H>
extern Fl_Browser *brw_results;
extern Fl_Browser *brw_extn;
extern Fl_Menu_Item menu_[];
#define menu_dependson (menu_+2)
#define menu_requiredby (menu_+3)
#define menu_missing (menu_+4)
#define menu_nodepends (menu_+5)
#define menu_auditall (menu_+6)
#define menu_delete (menu_+7)
#define menu_marked (menu_+8)
#endif