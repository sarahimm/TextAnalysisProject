//Sarah Immel
//CS 172-1
//5/13/20
//
//This file is part of Sarah Immel's CS 172 Final Project. 
//For resources/works cited, see documentation (via the link in the included Documentation/Presentation_Links.txt file)
#ifndef PROSE_H
#define PROSE_H
#include "Text.h"
class Prose : public Text{
    private:
        //Number of sentences
        int sentences;
        //Average words per sentence
        float avg_sentence_length;
        //Reading level--based off of Flesch-Kincaid model, with an estimate of 3 letters per syllable
        //Score=206.835-1.015(total words/total sentences)-84.6(total syllables/total words)
        //100-90: 5th grade     90-80: 6th      80-70:7th       70-60:8th/9th       60-50:10th/12th     50-30:College       30-0:College graduate
        float reading_lvl;
        //Percentage (in words) of dialogue
        float prcnt_dialogue;
        //Settor for sentences and avg_sentence_length
        void set_sentence();
        //Settor for reading_lvl
        void set_reading_lvl();
        //Settor for prcnt_dialogue
        void set_dialogue();
    public:
        //Default constructor
        Prose();
        //Full constructor
        Prose(string Title, string Address);
        //Returns all relevant data for the prose, including the top (int w) most used words
        string to_str(int w);
        //Changes address and recalculates all member variables of Prose and Text
        void set_address(string Address);
        //Gettor for sentences
        int get_sentences();
        //Gettor for avg_sentence_length();
        float get_avg_sentence();
        //Gettor for reading level
        float get_reading_lvl();
        //Gettor for prcnt_dialogue
        float get_dialogue();



};

#endif