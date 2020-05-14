//Sarah Immel
//CS 172-1
//5/13/20
//
//This file is part of Sarah Immel's CS 172 Final Project. 
//For resources/works cited, see documentation (via the link in the included Documentation/Presentation_Links.txt file)
#include "../headers/Prose.h"
#include <fstream>
#include <string>
using namespace std;

//Settor for sentences and avg_sentence_length
void Prose::set_sentence(){
    file.open(address);
    string str;
    sentences=0;
    while(file>>str){
        if(str[str.length()-1]=='.')
            sentences++;
    }
    avg_sentence_length=(0.0+length)/sentences;
    file.close();
}
//Settor for reading_lvl
void Prose::set_reading_lvl(){
    reading_lvl=206.835-1.015*(avg_sentence_length)-84.6*(avg_word_length/3);
}
//Settor for prcnt_dialogue
void Prose::set_dialogue(){
    file.open(address);
    bool isQuote=false;
    int quoteWords=0;
    string str;
    while(file>>str){
        if(str.length()>0){
            if(str[0]=='"'){
                isQuote=true;
            }
            if(str[str.length()-1]=='"'){
                quoteWords++;
                isQuote=false;
            }
            if(isQuote)
                quoteWords++;
        }
    }
    prcnt_dialogue=100*(quoteWords+0.0)/length;
    file.close();
}
//Default constructor
Prose::Prose() : Text(){
    sentences=0;
    avg_sentence_length=0;
    reading_lvl=0;
    prcnt_dialogue=0;
}
//Full constructor
Prose::Prose(string Title, string Address) : Text(Title,Address){
    set_sentence();
    set_reading_lvl();
    set_dialogue();
}
//Returns all relevant data for the prose, including the top (int w) most used words
string Prose::to_str(int w){
    string str= "Title: "+title+"\nType: Prose\nReading level: "+to_string(reading_lvl);
    if(reading_lvl>100) str+=" (below 5th grade)";
    else if(reading_lvl>90) str+=" (5th grade)";
    else if(reading_lvl>80) str+=" (6th grade)";
    else if(reading_lvl>70) str+=" (7th grade)";
    else if(reading_lvl>60) str+=" (8th/9th grade)";
    else if(reading_lvl>50) str+=" (10th/12th grade)";
    else if(reading_lvl>30) str+=" (College)";
    else str+=" (College graduate)";
        str+="\nLength: "+to_string(length)+" words\n\t"+to_string(sentences)+
            " sentences\nAverage sentence length: "+to_string(avg_sentence_length)+" words\nPercent dialogue: "
            +to_string(prcnt_dialogue)+"%\nDistinct words: "+to_string(words.size())+
            "\nPercent unique words: "+to_string(prcnt_unique)+"%\nAverage word length: "+to_string(avg_word_length)+
            " letters\nAverage word frequency: "+to_string(avg_word_freq)+" appearances\nMost frequently used words:\n";
    vector<string> str_vec;
    vector<int> num_vec;
    if(w>freqs.size())
        w=freqs.size();
    most_freq(w,str_vec,num_vec);
    for(int i=0;i<w;i++){
        str+="\t"+to_string(i+1)+". \""+str_vec[i]+"\" occurred "+to_string(num_vec[i])+" times.\n";
    }
    return str;
}
//Changes address and recalculates all member variables of Prose and Text
void Prose::set_address(string Address){
            address=Address;
            set_words();
            set_length();
            set_prcnt_unique();
            set_avg_word_length();
            set_avg_word_freq();
            set_sentence();
            set_reading_lvl();
            set_dialogue();
}
//Gettor for sentences
int Prose::get_sentences(){
    return sentences;
}
//Gettor for avg_sentence_length
float Prose::get_avg_sentence(){
    return avg_sentence_length;
}
//Gettor for reading level
float Prose::get_reading_lvl(){
    return reading_lvl;
}
//Gettor for prcnt_dialogue
float Prose::get_dialogue(){
    return prcnt_dialogue;
}