

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
unordered_set<string> temporarylist;

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
void Get_Starting_words(vector<string>Givenvector)

{
	//queue<stack<string>> Queuestack;
	//stack<string> Eachword;

	for (string word : Givenvector)
		temporarylist.insert(word);
	//string initialword = "";
	string word1, word2;
	queue<string> wordsqueue;
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
		//Eachword.push(word1);
		wordsqueue.push(word1);
		//Queuestack.push(Eachword);
		//string word3 = word1;
	
		string word = "";
		while (!wordsqueue.empty())
		{
			++foundlevel;
			int size = wordsqueue.size();
			for (int i = 0; i < size; i++) {
				word = wordsqueue.front();
				
				wordsqueue.pop();

				for (int i = 0; i < word.size(); i++)
				{

					string temp = word;
					for (char c = 'a'; c <= 'z'; c++)
					{
						temp[i] = c;

						if (word.compare(temp) == 0)
							continue;
				
						if (temporarylist.find(temp) != temporarylist.end())
						{
							wordsqueue.push(temp);
							
							temporarylist.erase(temp);
						}
						
                  
						}
				
						
				

				}
			
				
		cout << word << " =>";
		
			if (word.compare(word2) == 0) {
				cout << "it is found at " << foundlevel + 1;
				exit(0);
			}
				
			}
			
			
		}
	}




	else
		cout << " the word not found in English words\n";


}
int main()//main function to call all functions
{


	
	//cout << endl << "ENTER THE LETTERS YOU THINK CAN MAKE THE HIDEN WORD BELOW \n";
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
	/*for (string all : Givenvector)
		cout << all << endl;*/


	
	
	Get_Starting_words(Givenvector);

	
}
