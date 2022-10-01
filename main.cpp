#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "timer.h"
#include "BST.h"

string cleanWord(const string s);
BST<string> initDict();

int main()
{
    // variables that we will report at the end
    int spelledCorrectly = 0;
    long long correctCompares = 0;
    int spelledIncorrectly = 0;
    long long incorrectCompares = 0;
    int skipped = 0;

    // linked lists for the dictionary and mispelled words
    BST<string> dict = initDict();
    BST<string> misspelled = BST<string>();

    ifstream bookIn;
    bookIn.open("book.txt");

    Timer t;
    t.Start();

    // Main loop to check words in the book against the dictionary
    string buffer;
    while (bookIn >> buffer)
    {
        buffer = cleanWord(buffer);

        // We will not count the word if it is blank after cleaning
        if (buffer.empty())
            continue;

        long checks = 0;
        // If the first letter of the word starts with a letter, check it. Otherwise skip it and increment the skip counter
        if (buffer[0] >= (int) 'a' && buffer[0] <= (int) 'z')
        {
            // Run the find method to see if the word is in the dictionary
            // We are passing in a reference to checks, which will increment every time a check is made
            if (dict.find(buffer, checks))
            {
                spelledCorrectly++;
                correctCompares += checks;
            }
            else
            {
                spelledIncorrectly++;
                incorrectCompares += checks;
                misspelled.insert(buffer);
            }
        }
        else
        {
            skipped++;
        }
    }

    t.Stop();

    bookIn.close();

    //misspelled.printToFile("misspelled.txt");

    cout << "Dictionary Size: " << dict.getNumberOfNodes() << endl;
    cout << "Done checking and these are the results" << endl;
    cout << "Finished in time " << t.Time() << endl;
    cout << "There are " << spelledCorrectly << " words found in the dictionary" << endl;
    cout << "\t" << correctCompares << " compares. Average: " << correctCompares / spelledCorrectly << endl;
    cout << "There are " << spelledIncorrectly << " words NOT found in the dictionary." << endl;
    cout << "\t" << incorrectCompares << " compares. Average: " << incorrectCompares / spelledIncorrectly << endl;
    cout << "There are " << skipped << " words not checked." << endl;

    return 0;
}

string cleanWord(const string s)
{
    string output = "";

    // Loop through each character
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        // if the character is alphanumeric or an apostrophe, keep it and push it to the output string
        if (isalnum(c) || c == '\'')
        {
            output.push_back(tolower(c));
        }
    }

    return output;
}

BST<string> initDict()
{
    BST<string> dict = BST<string>();

    ifstream dictIn;
    dictIn.open("dict.txt");

    // get each line from the file
    string buffer = "";
    while (getline(dictIn, buffer))
    {
        buffer = cleanWord(buffer);

        // If the cleaned word is blank, dont add it, otherwise add it to the dictionary (BST) object
        if (!buffer.empty())
        {
            dict.insert(buffer);
        }
    }

    dictIn.close();
    return dict;
}