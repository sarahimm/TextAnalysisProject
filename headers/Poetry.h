//Sarah Immel
//CS 172-1
//5/13/20
//
//This file is part of Sarah Immel's CS 172 Final Project. 
//For resources/works cited, see documentation (via the link in the included Documentation/Presentation_Links.txt file)
#ifndef POETRY_H
#define POETRY_H
#include "Text.h"
using namespace std;

class Poetry : public Text{
    private:
        //Total number of lines in the text
        int lines;
        //Average words per line (excluding blank lines)
        float avg_line_length;
        //Settor for lines and avg_line_length; should only be called by constructor and set_address
        void set_avg_line_length();
    public:
        //Default constructor
        Poetry();
        //Full constructor
        Poetry(string title, string address);
        //Gettor for lines
        int get_lines();
        //Gettor for avg_line_length
        float get_avg_line_length();
        //Returns all relevant data for the poem(s), including the top (int w) most used words
        string to_str(int w);
        //Changes address and recalculates all member variables of Poetry and Text
        void set_address(string Address);
};

#endif