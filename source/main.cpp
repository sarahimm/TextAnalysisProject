//Sarah Immel
//CS 172-1
//5/13/20
//
//This file is part of Sarah Immel's CS 172 Final Project. 
//For resources/works cited, see documentation (via the link in the included Documentation/Presentation_Links.txt file)


#include "../headers/Poetry.h"
#include "../headers/Prose.h"
#include "../headers/Text.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


int main(){
//Title
    vector<Text*> texts;
    bool done=false;
    cout<<"\n\t| Text Analyzer |";
//Input file loop
    do{
        char choice;
        cout<<"\n\nPlease choose from the following:\n\ta)Add a text file\n\tb)Choose from sample texts\nEnter the letter of your choice here: ";
        cin>>choice;
    //Add a text file by address
        if(choice=='a'){
            string address;
            string title;
            char type;
            cin.ignore();
            cout<<"Enter the file path here: ";
            getline(cin,address);
            cout<<"Enter a title: ";
            getline(cin,title);
            cout<<"Is this: a)Poetry  b)Prose  or  c)Other?\nEnter the corresponding letter here: ";
            cin>>type;
            if(type=='a')
                texts.push_back(new Poetry(title,address));
            else if(type=='b')
                texts.push_back(new Prose(title,address));
            else
                texts.push_back(new Text(title,address));            
        }//Display sample texts; allow user to add one to the vector
        else{
            char sample;
            cout<<"\nHere are the available samples:\n\ta)A Tale of Two Cities by Charles Dickens\n\tb)Paradise Lost by John Milton"
                <<"\n\tc)Poems by Emily Dickinson\n\td)Pride and Prejudice by Jane Austen\n\te)Sonnets by William Shakespeare"
                <<"\n\tf)The Wonderful Wizard of Oz by L. Frank Baum\nEnter the corresponding letter here: ";
            cin>>sample;
            if(sample=='a') texts.push_back(new Prose("A Tale of Two Cities",));
            else if(sample=='b') texts.push_back(new Poetry("Paradise Lost","..\\Sample_texts\\Paradise_lost_sample_poem.txt"));
            else if(sample=='c') texts.push_back(new Poetry("Poems by Emily Dickinson","..\\Sample_texts\\Dickinson_sample_poems.txt"));
            else if(sample=='d') texts.push_back(new Prose("Pride and Prejudice","..\\Sample_texts\\Pride_and_prejudice_sample_prose.txt"));
            else if(sample=='e') texts.push_back(new Poetry("Shakespeare's Sonnets","..\\Sample_texts\\Shakespeare_sonnets_sample_poems.txt"));
            else if(sample=='f') texts.push_back(new Prose("The Wonderful Wizard of Oz","..\\Sample_texts\\Wizard_of_oz_sample_prose.txt"));
            else cout<<"Invalid selection\n";
        }
    //Prompt to add another file or exit the loop
        char cont;
        cout<<"You have selected "<<texts.size()<<" files. Would you like to add another? (y/n)\n";
        cin>>cont;
        if(cont=='n')
            done=true;
    }while(!done);
    done=false;
//Loop for options to display data
    do{
        char action;
        int num_words;
        cout<<"\nWhat would you like to do now?\n\ta)Print data for all texts\n\tb)Print data for a single text\n\tc)Search for a given word"
            <<"\n\td)View top words side-by-side\n\te)Change a title\n\tf)Change an address (note: this will recalculate all text data)"
            <<"\n\tg)Exit\nEnter the letter corresponding to your choice here: ";
        cin>>action;
    //Print data for all texts
        if(action=='a'){
            cout<<"How many of the top words would you like printed for each text? ";
            cin>>num_words;
            cout<<endl<<endl;
            for(int i=0;i<texts.size();i++){
                cout<<texts[i]->to_str(num_words)<<endl<<endl;
            }
        }
    //Print data for a single text
        else if(action=='b'){
            int txt_choice;
            cout<<"Which text's statistics would you like to view?\n";
            for(int i=0;i<texts.size();i++){
                cout<<i+1<<". "<<texts[i]->get_title()<<endl;
            }
            cout<<"Enter the corresponding number here: ";
            cin>>txt_choice;
            cout<<"How many of its top words would you like to view? Enter here: ";
            cin>>num_words;
            cout<<endl;
            cout<<texts[txt_choice-1]->to_str(num_words)<<endl<<endl;
        }
    //Search for a user-defined word in every text and output # of occurrences in each
        else if(action=='c'){
            string word;
            cout<<"Which word would you like to search for?\n";
            cin>>word;
        //Remove formatting from inputted word
            for(int i=0; i<word.length(); i++){
                if(word[i]<'A' || word[i]>'z' || (word[i]>'Z' && word[i]<'a')){	//Remove punctuation
                    word.erase(i,1);
                    i--;
                }else{					//Make lowercase
                    word[i]=tolower(word[i]);
                }
            }
        //Output occurrences
            for(int i=0;i<texts.size();i++){
                cout<<setw(30)<<right<<texts[i]->get_title()<<setw(0)<<": \""<<word<<"\" occurred "<<texts[i]->find_freq(word)<<" times."<<endl;
            }
        }
    //Print the top words of all texts side-by-side
        else if(action=='d'){
            cout<<"How many of the top words would you like printed for each text? ";
            cin>>num_words;
            vector<vector<string>> topStrs;
            vector<vector<int>> topInts;
        //Print titles and initialize parallel vectors for each text
            cout<<endl<<endl<<"     ";
            for(int i=0;i<texts.size();i++){
                cout<<setw(30)<<right<<texts[i]->get_title();
                vector<string> topStr;
                vector<int> topInt;
                texts[i]->most_freq(num_words,topStr,topInt);
                topStrs.push_back(topStr);
                topInts.push_back(topInt);
            }
        //Print each line of output
            for(int i=0;i<num_words;i++){
                cout<<endl<<setw(5)<<right<<i+1<<".";
            //Print data from vectors of each text
                for(int j=0;j<texts.size();j++){
                    if(i<topStrs[j].size())
                        cout<<setw(13)<<right<<(topStrs[j])[i]<<setw(2)<<"  "<<setw(13)<<left<<(topInts[j])[i]<<setw(2)<<"|";
                    else cout<<setw(15)<<right<<"[n/a]"<<setw(15)<<left<<"|";
                }
            }
            cout<<endl<<endl;
        }
    //Change the title of a text
        else if(action=='e'){
            int choice;
            string title;
            cout<<"Which title would you like to change?\n";
            for(int i=0;i<texts.size();i++){
                cout<<i+1<<". "<<texts[i]->get_title()<<endl;
            } 
            cout<<"Enter the corresponding number here: ";
            cin>>choice;
            cin.ignore();
            cout<<"Enter the new title here:\n";
            getline(cin,title);
            texts[choice-1]->set_title(title);
            cout<<endl<<endl;
        }
    //Change the address (and all associated parameters) of a text
        else if(action=='f'){
            int choice;
            string address;
            cout<<"Which address would you like to change?\n";
            for(int i=0;i<texts.size();i++){
                cout<<i+1<<". "<<texts[i]->get_title()<<endl<<"  "<<texts[i]->get_address()<<endl;
            } 
            cout<<"Enter the corresponding number here: ";
            cin>>choice;
            cin.ignore();
            cout<<"Enter the new address here:\n";
            getline(cin,address);
            texts[choice-1]->set_address(address);
            cout<<endl<<endl;
        }
    //Exit the loop
        else if(action=='g'){
            done=true;
        }
        else{
            cout<<"Invalid selection\n";
        }
    }while(!done);
//Clean up!
    for(int i=0;i<texts.size();i++){
        delete texts[i];
    }
}