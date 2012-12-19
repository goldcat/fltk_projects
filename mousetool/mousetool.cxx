// generated by Fast Light User Interface Designer (fluid) version 1.0109

#include "mousetool.h"
// (c) Robert Shingledecker 2008
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
static string mouseType; 
static string selectedSpeed="3"; 

void dial_callback(Fl_Widget*, void*) {
  ostringstream myStrStream;
myStrStream << (int)dial_speed->value();
selectedSpeed = myStrStream.str();
box_speed->label(selectedSpeed.c_str());
}

void btn_callback(Fl_Widget*, void* userdata) {
  if (userdata == "exit")
   exit(0);

string pointerOrder;

if (btn_right->value() == 1)
{
   if (mouseType == "3")
      pointerOrder = "1 2 3";
   else
      pointerOrder = "1 2 3 4 5";
} else 
{
   if (mouseType == "3")
      pointerOrder = "3 2 1";
   else
      pointerOrder = "3 2 1 4 5";
}
         
string speedCmd = "xset m " + selectedSpeed + "/1 0";
string handednessCmd = "xmodmap -e \'pointer = " + pointerOrder +"\'";

ofstream fout(".mouse_config", ios::out | ios::out);
if (!fout.is_open() )
{
   cerr << "Can't open .mouse_config for output." << endl;
   exit(EXIT_FAILURE);
}
fout << speedCmd << endl;
fout << handednessCmd << endl;
fout.close();
system( speedCmd.c_str() );
system( handednessCmd.c_str() );
system( "chmod +x .mouse_config" );
}

Fl_Dial *dial_speed=(Fl_Dial *)0;

Fl_Box *box_speed=(Fl_Box *)0;

Fl_Round_Button *btn_right=(Fl_Round_Button *)0;

Fl_Round_Button *btn_left=(Fl_Round_Button *)0;

int main(int argc, char **argv) {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(145, 200, "Mouse Tool");
    w = o;
    { dial_speed = new Fl_Dial(45, 20, 50, 50, "Mouse Speed");
      dial_speed->minimum(1);
      dial_speed->maximum(10);
      dial_speed->step(1);
      dial_speed->value(3);
      dial_speed->callback((Fl_Callback*)dial_callback);
      dial_speed->align(FL_ALIGN_TOP);
    } // Fl_Dial* dial_speed
    { box_speed = new Fl_Box(55, 75, 30, 23);
      box_speed->label("3");
    } // Fl_Box* box_speed
    { btn_right = new Fl_Round_Button(20, 100, 103, 20, "Right Button");
      btn_right->down_box(FL_ROUND_DOWN_BOX);
      btn_right->value(1);
      btn_right->selection_color((Fl_Color)2);
      btn_right->type(FL_RADIO_BUTTON);
    } // Fl_Round_Button* btn_right
    { btn_left = new Fl_Round_Button(20, 120, 103, 20, "Left Button");
      btn_left->down_box(FL_ROUND_DOWN_BOX);
      btn_left->selection_color((Fl_Color)2);
      btn_left->type(FL_RADIO_BUTTON);
    } // Fl_Round_Button* btn_left
    { Fl_Button* o = new Fl_Button(20, 155, 50, 25, "&Apply");
      o->callback((Fl_Callback*)btn_callback, (void*)("apply"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(75, 155, 50, 25, "&Exit");
      o->callback((Fl_Callback*)btn_callback, (void*)("exit"));
    } // Fl_Button* o
    o->end();
  } // Fl_Double_Window* o
  FILE *CMD_fp = NULL;
if ((CMD_fp = popen("xmodmap -pp|head -1|cut -f3 -d' '","r"))==NULL)
{
   cerr << "popen failed" << endl;
   return 1;
}
char result[1024];
if ( fgets(result,1023,CMD_fp)==NULL)
{
   cerr << "popen results returned NULL" << endl;
   return 1;
}
mouseType = result;
  w->show(argc, argv);
  return Fl::run();
}