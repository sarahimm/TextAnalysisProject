UML digram available via this link:
https://drive.google.com/file/d/1RiLYuaJRVqQs1TqUQeVrODo0fJT_t4Au/view?usp=sharing

Presentation available via this link:
https://drive.google.com/file/d/1oNYhMaqI-S2WWbvEDVmqXqPGDVbc3cCY/view?usp=sharing
# Purpose
This program was created to analyze given texts for metrics such as sentence length, word frequency, and reading level. These metrics are stored in instances of the appropriate class: Text (for generic or mixed-genre .txt files) and its derived classes, Prose and Poetry.

The main.cpp program in this file guides the user through inputting their own .txt files (sample text files are also available) and viewing the data stored in the Text object, allowing them to compare the properties of various texts.

# Assumptions
Standard text formatting is assumed in each of the inputted text files--words must be separated by spaces, sentences by a period followed by at least one space. Anything in the file is assumed to be part of the text, so titles, prefaces, etc. _will_ affect the results.

Prose objects will only compute percent dialogue correctly if the text file contains straight quotes, __not curly/smart quotes!__ Dialogue enclosed in curly quotes will not be recognized as such.

# Instructions
This program will take valid addresses for .txt files and print out data and statistics pertaining to the text's type. All user input will be prompted by the program and should be self-explanatory.

## Some important notes:
* If you enter an invalid address, the program will continue to prompt you for a new address until a valid address is provided.
* Currently, you cannot remove texts or add new texts to the vector after you have indicated that you are done adding files.
* If you request more top words than the text object contains, the program will print only as many objects as are stored in the object's "words" map
    * However, selecting the "side-by-side" option will fill the remainder of the lines of output with [n/a]

# Public Class Functions Explained
(see also header comments in the .h files)
### Text.h
* Text(): Default constructor. Initializes all variables to "" or 0
* Text(string Title, string Address): Full constructor. Calls a number of private settor functions to analyze the text and store values in member variables
* most_freq(int w, vector<string>& strings, vector<int>& nums): Fills 'strings' and 'nums' with parallel lists of the top [w] most frequent words in the text. 
  * __NOTE__: Any preexisting elements of strings and nums will be cleared
* to_str(int w): returns a string containing all relevant data for the text, including the [w] most frequent words
  * __NOTE__: This is a virtual method
* find_freq(string str): returns an integer value containing the number of occurrences of 'str' within the text
* set_title(string Title): changes the text's title
* set_address(string address): changes the text's address and calls all private settors to recalculate the text's data
  * __NOTE__: This will change all of the member variables except 'title.'
  * __NOTE__: This is a virtual method
* get_address(): returns the file path as a string
* get_words(): returns a map<string,int> of every word in the text(string) paired with its frequency(int)
* get_prcnt_unique(): returns a float containing the percentage of total words which appear only once in the text
* get_avg_word_length(): returns the average number of characters in each word (not including punctuation) as a float
* get_avg_word_frequency(): returns as a float the average number of times each word appears in the text
* get_length(): returns as an int the total length of the text, in words

### Poetry.h
* Poetry(): Default constructor. Calls Text() and initializes all variables to "" or 0
* Poetry(string title, string address): Full constructor. Calls Text(title, address), then initializes Poetry's member variables using private settor functions
* get_lines(): Returns as an int the number of lines in the text
* get_avg_line_length(): Returns the average number of words per line as a float
* to_str(int w): Returns all relevant data as a string, including the [w] most frequent words
* set_address(string Address): see notes on Text::set_address()

### Prose.h
* Prose(): Default constructor. Calls Text() and initializes all variables to "" or 0
* Prose(string title, string address): Full constructor. Calls Text(title, address), then initializes Prose's member variables using private settor functions
* get_sentences(): returns the total number of sentences in the text as an int
* get_avg_sentence(): returns the average sentence length, in words, as a float
* get_reading lvl(): returns the reading level based off of the Flesch-Kincaid model
  * Score = 206.835 - 1.015 * (words per sentences) - 84.6 * (syllables per word)
    * __NOTE__: this function assumes that each syllable is three letters and uses avg_word_length/3 for syllables per word
  * 100-90.0: 5th grade
  * 90-80.0:  6th grade
  * 80-70.0:  7th grade
  * 70-60.0:  8th/9th grade
  * 60-50.0:  10th-12th grade
  * 50-30.0:  College
  * 30-0.0:   College graduate

# Works Cited
While all of the code within this directory is my original work, I did reference several websites to view C++ documentation and example code. The resources I consulted are the following:
* C++ Reference: http://www.cplusplus.com/reference/
  * Primarily consulted for information on std::map
* C++ Forum: http://www.cplusplus.com/forum/general/85171/
  and http://www.cplusplus.com/forum/beginner/123379/
  * Used as examples to learn how to insert elements into a map, then iterate through them

The formula and values which I used for the Flesch-Kincaid reading levels come from Wikipedia: https://en.wikipedia.org/wiki/Flesch%E2%80%93Kincaid_readability_tests

The included UML diagram (see link at the top of this file) was created using http://www.lucidchart.com

Lastly, the sample texts included in this directory were downloaded and slightly adapted (preface/epilogue material removed, curly quotes changes to straight quotes) from Project Gutenberg: https://www.gutenberg.org/