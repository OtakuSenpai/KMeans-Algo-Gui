#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>

#include <stdlib.h>
#include <string>
#include <fstream>

#include "KmeansReader.hpp"


class KmeansGui : public Fl_Window {

  private:
     Fl_Native_File_Chooser *fc;
     Fl_Menu_Bar *menu;
     Fl_Box *box;

     KMeans kmeans;

     // used to check if the file is present or not
     bool exist(const std::string& filename);

     // read the data from the file
     void open(const std::string& filename);

     // save the processed data
     void save_data(const std::string& filename);

     // Handle an 'Open' request from the menu
     static void open_cb(Fl_Widget *w, void *v) {
       KmeansGui *app = reinterpret_cast<KmeansGui*>(v);
       app->fc->title("Open data file");
       app->fc->type(Fl_Native_File_Chooser::BROWSE_FILE);    // only picks files that exist
       switch( app->fc->show() ) {
         case -1: break;  // Error
         case  1: break;  // Cancel
         default:   // Choice
           app->fc->preset_file(app->fc->filename());
           app->open(std::string(app->fc->filename()));
           break;
       }
     }

     // Handle a 'Save as' request from the menu
     static void saveas_cb(Fl_Widget *w, void *v) {
       KmeansGui *app = reinterpret_cast<KmeansGui*>(v);
       app->fc->title("Save As");
       app->fc->type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE); // need this if file doesn't exist yet
       switch( app->fc->show() ) {
         case -1: break;  // Error
         case  1: break;  // Cancel
         default:   // Choice
         app->fc->preset_file(app->fc->filename());
         app->save_data(std::string(app->fc->filename()));
         break;
      }
    }

     // Handle a 'Save' request from the menu
     static void save_cb(Fl_Widget *w, void *v) {
       KmeansGui *app = reinterpret_cast<KmeansGui*>(v);
       if(strlen(app->fc->filename()) == 0 ) {
         saveas_cb(w,v);
       } else {
         app->save_data(std::string(app->fc->filename()));
       }
     }

     static void quit_cb(Fl_Widget *w, void *v) {
       exit(0);
     }

     const char* untitled_default() {
       static char *filename = 0;
       if ( !filename ) {
         const char *home = getenv("HOME") ? getenv("HOME") :    // unix
           getenv("HOME_PATH") ? getenv("HOME_PATH") :   // windows
           ".";            // other
         filename = (char*)malloc(strlen(home)+20);
         sprintf(filename, "%s/untitled.txt", home);
       }
       return(filename);
     }

  public:

     KmeansGui() : Fl_Window(400,200,"KMeans Algo Demo") {}

     void initialise() {
       menu = new Fl_Menu_Bar(0,0,400,25);
       menu->add("&File/&Open Data File",  FL_COMMAND+'o', open_cb, reinterpret_cast<void*>(this));
       menu->add("&File/&Save",  FL_COMMAND+'s', save_cb, reinterpret_cast<void*>(this));
       menu->add("&File/&Save As", 0,  saveas_cb, reinterpret_cast<void*>(this));
       menu->add("&File/&Quit",  FL_COMMAND+'q', quit_cb);
       // Describe the demo..
       box = new Fl_Box(20,25+20,w()-40,h()-40-25);
       box->color(45);
       box->box(FL_FLAT_BOX);
       box->align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE|FL_ALIGN_WRAP);
       box->label("KMeans Algo Demo made by students of UEM-K :-  "
                  "Roumyak Biswas, CSE-3F Roll 66\n"
                  "And Avra Neel Chakraborty, CSE 3F Roll 65\n"
                  "..using the FLTK cross platform GUI library.\n\n");
       box->labelsize(12);
       // Initialize the file chooser
       fc = new Fl_Native_File_Chooser();
       fc->filter("Text\t*.txt\n");
       fc->preset_file(untitled_default());
       end();
     }
};
