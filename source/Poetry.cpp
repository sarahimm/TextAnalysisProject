//Sarah Immel
//CS 172-1
//5/13/20
//
//This file is part of Sarah Immel's CS 172 Final Project. 
//For resources/works cited, see documentation (via the link in the included Documentation/Presentation_Links.txt file)
        #include "..\headers\Poetry.h"

        //Settor for lines and avg_line_length; should only be called by constructor and set_address
        void Poetry::set_avg_line_length(){
            file.open(address);
            lines=0;
            string line;
            while(getline(file,line)){
                if(line.length()>0)
                    lines++;
            }
            file.close();
            avg_line_length=(0.0+length)/lines;
        }
        //Default constructor
        Poetry::Poetry() : Text(){
            avg_line_length=0;
            lines=0;
        }
        //Full constructor
        Poetry::Poetry(string title, string address) : Text(title,address){
            set_avg_line_length();
        }
        //Gettor for lines
        int Poetry::get_lines(){
            return lines;
        }
        //Gettor for avg_line_length
        float Poetry::get_avg_line_length(){
            return avg_line_length;
        }
        //Returns all relevant data for the poem(s), including the top (int w) most used words
        string Poetry::to_str(int w){
            string str= "Title: "+title+"\nType: Poetry\nLength: "+to_string(length)+" words\n\t"+to_string(lines)+
                    " lines\nAverage line length: "+to_string(avg_line_length)+" words\nDistinct words: "+to_string(words.size())+
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
        //Changes address and recalculates all member variables of Poetry and Text
        void Poetry::set_address(string Address){
            address=Address;
            set_words();
            set_length();
            set_prcnt_unique();
            set_avg_word_length();
            set_avg_word_freq();
            set_avg_line_length();
        }