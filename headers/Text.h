//Sarah Immel
//CS 172-1
//5/13/20
//
//This file is part of Sarah Immel's CS 172 Final Project. 
//For resources/works cited, see documentation (via the link in the included Documentation/Presentation_Links.txt file)

#ifndef TEXT_H
#define TEXT_H
#include <string>
#include<vector>
#include<map>
#include<fstream>
using namespace std;
class Text{
    protected:
        //Name of text
        string title;
        //Address of file
        string address;
        //Used to access the file
        ifstream file;
        //Stores all words (alphabetical) and their frequencies)
        map<string,int> words;
        //Stores words sorted by frequency
        multimap<int,string> freqs;
        //Percentage of words used only once in the text
        float prcnt_unique;
        //Average word length
        float avg_word_length;
        //How often a word occurs within the text on average
        float avg_word_freq;
        //Total length of the text (in words)
        int length;
        //Settor for words and freqs--should only be called when an object is first constructed or when the address is changed
        void set_words();
        //Settor for prcnt_unique--should only be called when an object is first constructed or when the address is changed
        void set_prcnt_unique();
        //Settor for avg_word_length--should only be called when an object is first constructed or when the address is changed
        void set_avg_word_length();
        //Settor for avg_word_freq--should only be called when an object is first constructed or when the address is changed
        void set_avg_word_freq();
        //Settor for length--should only be called when an object is first constructed or when the address is changed
        void set_length();
    public:
        //Default constructor; initializes all values to empty or 0
        Text();
        //Full constructor; initializes all member variables
        Text(string Title, string Address);
        //Clears both vectors and fills them with the top [w] most frequent words and their counts
        void most_freq(int w, vector<string>& strings, vector<int>& nums);
        //Returns all relevant data for the text's type, including the top (int w) most used words (defaults to 20)
        virtual string to_str(int w);
        //Finds the number of occurrences of the given word;
        int find_freq(string str);
        //Settor for title
        void set_title(string Title);
        //Gettor for title
        string get_title();
        //Settor for address; changing the address will automatically reset the other member variables 
        virtual void set_address(string Address);
        //Gettor for address
        string get_address();
        //Gettor for words
        map<string,int> get_words();
        //Gettor for percent unique
        float get_prcnt_unique();
        //Gettor for average word length
        float get_avg_word_length();
        //Gettor for average word frequency
        float get_avg_word_freq();
        //Gettor for length
        int getlength();

};

#endif