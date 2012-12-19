// generated by Fast Light User Interface Designer (fluid) version 1.0109

#include "cpanel.h"
// (c) Robert Shingledecker 2008
#include <iostream>
using namespace std;
static string home; 

void btn_callback(Fl_Widget* w, void* userdata) {
  Fl_Button* bp = (Fl_Button*)w;
if (userdata == "tftpd"){
  if(bp->box() == FL_DOWN_BOX){
    system("sudo pkill udpsvd");
    bp->box(FL_UP_BOX);
  } else {
    bp->box(FL_DOWN_BOX);
    string command = "sudo /sbin/udpsvd -E 0 69 tftpd " + home + " &";
    system(command.c_str());
  }
} else if (userdata == "ssh"){
  if(bp->box() == FL_DOWN_BOX){
    system("sudo /etc/init.d/dropbear stop");
    bp->box(FL_UP_BOX);
  } else {
    bp->box(FL_DOWN_BOX);
    system("sudo /etc/init.d/dropbear start");
  }
} else if (userdata == "udhcpc") {
  if(bp->box() == FL_DOWN_BOX){
    system("sudo pkill udhcpc");
    bp->box(FL_UP_BOX);
  } else {
    bp->box(FL_DOWN_BOX);
    system("sudo /sbin/udhcpc -b -i eth0");
  }
} else if (userdata == "crond") {
  if(bp->box() == FL_DOWN_BOX){
    system("sudo pkill crond");
    bp->box(FL_UP_BOX);
  } else {
    bp->box(FL_DOWN_BOX);
    system("sudo crond");
  }
} else {
  system((const char*)userdata);
}
}

Fl_Light_Button *tftpd=(Fl_Light_Button *)0;

Fl_Light_Button *ssh=(Fl_Light_Button *)0;

Fl_Light_Button *dhcpc=(Fl_Light_Button *)0;

Fl_Light_Button *crond=(Fl_Light_Button *)0;

int main(int argc, char **argv) {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(530, 170);
    w = o;
    { Fl_Button* o = new Fl_Button(10, 10, 120, 30, "Backup/Restore");
      o->callback((Fl_Callback*)btn_callback, (void*)("filetool &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(10, 50, 120, 30, "Date/Time");
      o->callback((Fl_Callback*)btn_callback, (void*)("datetool &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(10, 90, 120, 30, "Floppy Tool");
      o->callback((Fl_Callback*)btn_callback, (void*)("fdtool&"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(10, 130, 120, 30, "Help");
      o->callback((Fl_Callback*)btn_callback, (void*)("help &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(140, 10, 120, 30, "Netcardconfig");
      o->callback((Fl_Callback*)btn_callback, (void*)("sudo netcardconf &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(140, 50, 120, 30, "Backgrounds");
      o->callback((Fl_Callback*)btn_callback, (void*)("wallpaper &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(140, 90, 120, 30, "Apps Audit");
      o->callback((Fl_Callback*)btn_callback, (void*)("appsaudit &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(140, 130, 120, 30, "Mouse Tool");
      o->callback((Fl_Callback*)btn_callback, (void*)("mousetool &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(270, 10, 120, 30, "Mount Tool");
      o->callback((Fl_Callback*)btn_callback, (void*)("mnttool &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(270, 50, 120, 30, "Swapfile Tool");
      o->callback((Fl_Callback*)btn_callback, (void*)("swapfile &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(270, 90, 120, 30, "Select Mirror");
      o->callback((Fl_Callback*)btn_callback, (void*)("tcemirror &"));
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(270, 130, 120, 30, "System Stats");
      o->callback((Fl_Callback*)btn_callback, (void*)("stats &"));
    } // Fl_Button* o
    { tftpd = new Fl_Light_Button(400, 10, 120, 30, "TFTP Server");
      tftpd->selection_color((Fl_Color)2);
      tftpd->callback((Fl_Callback*)btn_callback, (void*)("tftpd"));
    } // Fl_Light_Button* tftpd
    { ssh = new Fl_Light_Button(400, 50, 120, 30, "SSH Server");
      ssh->color((Fl_Color)29);
      ssh->selection_color((Fl_Color)2);
      ssh->callback((Fl_Callback*)btn_callback, (void*)("ssh"));
    } // Fl_Light_Button* ssh
    { dhcpc = new Fl_Light_Button(400, 90, 120, 30, "DHCP Client");
      dhcpc->selection_color((Fl_Color)2);
      dhcpc->callback((Fl_Callback*)btn_callback, (void*)("udhcpc"));
    } // Fl_Light_Button* dhcpc
    { crond = new Fl_Light_Button(400, 130, 120, 30, "Cron Daemon");
      crond->selection_color((Fl_Color)2);
      crond->callback((Fl_Callback*)btn_callback, (void*)("crond"));
    } // Fl_Light_Button* crond
    o->end();
  } // Fl_Double_Window* o
  FILE *CMD_fp = NULL;
if ((CMD_fp = popen("env | awk -F'=' /HOME/'{printf \"%s\",$2}'","r"))==NULL)
{
   cout << "popen failed" << endl;
   return 1;
}
char result[1024];
if ( fgets(result,1023,CMD_fp)==NULL)     // If no result from above then default is to backup.
   home = "/home/tc";
else    
   home = result;     

if (system("pidof udpsvd > /dev/null") == 0)
{
   tftpd->box(FL_DOWN_BOX);
   tftpd->value(true);
} else
   tftpd->box(FL_UP_BOX); 

if (system("pidof dropbear >/dev/null") == 0)
{
   ssh->box(FL_DOWN_BOX);
   ssh->value(true);
} else
   ssh->box(FL_UP_BOX);
  
if (system("pidof udhcpc >/dev/null") == 0)
{
   dhcpc->value(true);
   dhcpc->box(FL_DOWN_BOX);
} else
   dhcpc->box(FL_UP_BOX);
   
if (system("pidof crond >/dev/null") == 0)
{
   crond->box(FL_DOWN_BOX);
   crond->value(true);
} else
   crond->box(FL_UP_BOX);
  w->show(argc, argv);
  return Fl::run();
}