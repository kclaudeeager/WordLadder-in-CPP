

#include<iostream>//including input and output stream
#include<fstream>//including file library
#include<vector> //including vector library
#include<random>//including randomisation
#include<string>//including strings
#include<ctime>//including c string library
#include<algorithm>
#include <queue>
#include<unordered_set>
#include<stack>

using namespace std;//


vector<string> get_text(ifstream& get)//a funtion that puts the file into a vector and returns the vector
{
	vector<string> strings;
	string d;
	while (get >> d) {
		strings.push_back(d);
	}
	
	return strings;
}

bool IsEnglish_word(string word ,vector<string> Givenvector)
{
	bool check = false;
	if (find(Givenvector.begin(), Givenvector.end(), word) != Givenvector.end())
		check=true;
	else
	{
		check = false;
	}
	//if (check == false) {
	//	
	//
	//}
	return check;
}
//Function to let the user enters the words to use in
//our game and returns the words entered by the user 
//if they are valid English words
vector<string> New_word_Ladder(string word, unordered_set<string>& dict)
{
	vector<string> res;

	// Find next word in dict by changing
	// each element from 'a' to 'z'
	for (int i = 0; i < word.size(); i++) {
		char s = word[i];
		for (char c = 'a'; c <= 'z'; c++) {
			word[i] = c;
			if (dict.find(word) != dict.end())
				res.push_back(word);
		}
		word[i] = s;//retain the orginal charcter
	}
	return res;
}
void display_Shortest_Path(vector<string >res)
{
	for (auto word:res) {
      cout << word << "=>";
		}

	
}
void WordLadder(vector<string>Givenvector)

{
	//queue<stack<string>> Queuestack;
	//stack<string> Eachword;

	unordered_set<string> temporarylist(Givenvector.begin(),Givenvector.end());
	//string initialword = "";
	string word1, word2;
	vector<vector<string> > Resultvectors;
	
	// Store visited words in list
	unordered_set<string> visit;

	// Queue used to find the shortest path
	queue<vector<string> >  wordsqueue;
	bool check = false;
	int foundlevel = 0;

	cout << "Enter the starting word and the target word you want\n";
	cin >> word1 >> word2;
	//change the written words into the lowercase
	std::transform(word1.begin(), word1.end(), word1.begin(),
		[](unsigned char c) { return std::tolower(c); });
	std::transform(word2.begin(), word2.end(), word2.begin(),
		[](unsigned char c) { return std::tolower(c); });


	
	if (word1._Equal(word2))
	{

		cout << "Two words should not be simillar\n";
		return;
	}


	if (word1.size() != word2.size())
	{
		cout << " the words must have the same length please\n";
		return;
	}
	//searching whether the entered words are valid english words

	
	if (IsEnglish_word(word1, Givenvector) and IsEnglish_word(word2, Givenvector))
	{
	

		wordsqueue.push({word1});
		while (!wordsqueue.empty())
		{
			int queuesize = wordsqueue.size();
			for(int i=0;i<queuesize;i++)
			{
				vector<string> currentword = wordsqueue.front();
				wordsqueue.pop();
				vector<string> new_vector;

				// Find words differing by a
				// single character
				new_vector = New_word_Ladder(currentword.back(), temporarylist);

				// Add words to the path.
				for (int j = 0; j < new_vector.size(); j++) {
					vector<string> New_word(currentword.begin(), currentword.end());

					New_word.push_back(new_vector[j]);
					if (new_vector[j] == word2) {
						check = true;
						Resultvectors.push_back(New_word);
					}

					visit.insert(new_vector[j]);
					wordsqueue.push(New_word);
					
				}
				

			}
			if (check) {
				
				break;
			}

			// Erase all visited words.
			for (auto visted : visit) {
				//cout << it << "=>";
				temporarylist.erase(visted);
			}

			visit.clear();//clearing all visted words
		}
	
	}




	else
		cout << " the word not found in English words\n";
	display_Shortest_Path(Resultvectors[0]);//displaying the path
	
}



int main()//main function to call all functions
{


	

	vector<string> strings;
	string word1, word2;
	ifstream ff;//reading the file
	ff.open("EnglishWords.dat");//openning the file
	string d;
	if (!ff)//checking if the file exists
	{

		cout << "loss of allocation \n";
	}
    vector<string>Givenvector=get_text(ff);//called functions
   WordLadder(Givenvector);


	
}
