//Sarah Immel
//CS 172-1
//5/13/20
//
//This file is part of Sarah Immel's CS 172 Final Project. 
//For resources/works cited, see documentation (via the link in the included Documentation/Presentation_Links.txt file)
#include "../headers/Text.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

//Settor for words--should only be called when an object is first constructed or when the address is changed
void Text::set_words(){
    fstream file;
    file.open(address);
    while(file.fail()){
        cin.ignore();
        cout<<endl<<"Error opening file at "<<address<<endl<<"Please enter a valid file path:\n";
        getline(cin,address);
        file.open(address);
    }
    string word;
    while(file>>word){          //Retrieve all words from file
        for(int i=0; i<word.length(); i++){
        if(word[i]<'A' || word[i]>'z' || (word[i]>'Z' && word[i]<'a')){	//Remove punctuation
            word.erase(i,1);
            i--;
        }else{					//Make lowercase
            word[i]=tolower(word[i]);
        }
    }
    if(word.length()!=0)
        words[word]++;          //Will increment word value if found, otherwise add word as an element of words with a value of 1
    }
    file.close();
    for(map<string,int>::iterator it=words.begin(); it!=words.end(); it++){
        freqs.insert({it->second,it->first});
    }
}
//Settor for length--should only be called when an object is first constructed or when the address is changed
//words map must already be initialized!!!
void Text::set_length(){
    length=0;
    for(map<string,int>::iterator it=words.begin(); it!=words.end(); it++){
        length += it->second;
    }
}
//Settor for prcnt_unique--should only be called when an object is first constructed or when the address is changed
//words and length must already be initialized
void Text::set_prcnt_unique(){
    float num_unique=0.0;
    for(map<string,int>::iterator it=words.begin(); it!=words.end(); it++){
        if(it->second == 1)
            num_unique++;
    }
    prcnt_unique = (num_unique/length)*100;
}
//Settor for avg_word_length--should only be called when an object is first constructed or when the address is changed
//words and length must already be initialized
void Text::set_avg_word_length(){
    float total_chars=0;
    for(map<string,int>::iterator it=words.begin(); it!=words.end(); it++){
        total_chars+= (it->first.length())*it->second;
    }
    avg_word_length = total_chars/length;
}
//Settor for avg_word_freq--should only be called when an object is first constructed or when the address is changed
//words and length must already be initialized
void Text::set_avg_word_freq(){
    avg_word_freq = (length+0.0)/words.size();
}
//Default constructor; initializes all values to empty or 0
Text::Text(){
    title="";
    address="";
    prcnt_unique=0;
    avg_word_length=0;
    avg_word_freq=0;
    length=0;
}
//Full constructor; initializes all member variables
Text::Text(string Title, string Address){
    title=Title;
    address=Address;
    set_words();
    set_length();
    set_prcnt_unique();
    set_avg_word_length();
    set_avg_word_freq();
}
//Clears both vectors and fills them with the top [w] most frequent words and their counts
void Text::most_freq(int w, vector<string>& strings, vector<int>& nums){
    multimap<int,string>::iterator it=freqs.end();
    if(w>freqs.size())
        w=freqs.size();
    strings.clear();
    nums.clear();
    for(int i=0; i<w; i++){
        it--;
        strings.push_back(it->second);
        nums.push_back(it->first);
    }
}
//Returns all relevant data for the text's type, including the top (w) most used words
string Text::to_str(int w){
    string str= "Title: "+title+"\nLength: "+to_string(length)+" words\nDistinct words: "+to_string(words.size())+
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
//Finds the number of occurrences of the given word;
int Text::find_freq(string str){
    map<string,int>::iterator it=words.find(str);
    if(it!=words.end())
        return it->second;
    else
        return 0;
}
//Settor for title
void Text::set_title(string Title){
    title=Title;
}
//Gettor for title
string Text::get_title(){
    return title;
}
//Settor for address; changing the address will automatically reset the other member variables 
void Text::set_address(string Address){
    address=Address;
    set_words();
    set_length();
    set_prcnt_unique();
    set_avg_word_length();
    set_avg_word_freq();
}
//Gettor for address
string Text::get_address(){
    return address;
}
//Gettor for words
map<string,int> Text::get_words(){
    return words;
}
//Gettor for percent unique
float Text::get_prcnt_unique(){
    return prcnt_unique;
}
//Gettor for average word length
float Text::get_avg_word_length(){
    return avg_word_length;
}
//Gettor for average word frequency
float Text::get_avg_word_freq(){
    return avg_word_freq;
}
//Gettor for length
int Text::getlength(){
    return length;
}