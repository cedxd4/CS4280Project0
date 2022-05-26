#include "shared.h"
#include "buildtree.cpp"
#include "binary.cpp"

string file = "temp.log";
using namespace std;

int c=1;
//this is to check to see if any letters or special characters are entered
void checkfile(string file)
{
	char check;
	ifstream infile;
	infile.open(file.c_str());
	while(infile)
	{
		check = getchar();
		if(islower(check))
		{
			check = getchar();
		}
		else
		{
			cout << "Must only be lowercase letters" << endl;
			exit (EXIT_FAILURE);
		}
	}
}

int main(int argc, char *argv[])
{
//this sends to buildtree program to get ready
	BuildTree tree;
	int ch=0;
	int count=0;
//once user just enters ./p0 they type what they want and on new line press ctrl+d which will start the program function
	if(argc == 1)
	{
		ofstream myfile;
		myfile.open("temp.log");
		cout << "Enter data and press Ctrl+d on a new line to signal end of file when finished.\n";
		int c;
		char typedletters;
		while ((c=getchar()) != EOF)
		{
			typedletters=c;
			myfile << typedletters;
		}
		myfile.close();
//reopens file to sort words and get all necessary info
		ifstream infile;
		infile.open("temp.log");
		string word;
		char a,b;
		checkfile(file);
		while(infile >> word)
		{

			int size=word.size();
			char wordArray[size];
			strcpy(wordArray,word.c_str());
			int rslt = tree.searchTree(wordArray[size-1], tree.root, word);
			count++;
		}
		infile.close();
		if (count == 0)
                {
                        cout << "You must enter a file that is not empty" << endl;
                        return -1;
                }

		int height=log(count)/log(2);
		cout << height << endl;
		levelorder(tree.root, "out.levelorder",height);
		preorder(tree.root, "out.preorder");
		inorder(tree.root, "out.inorder");
	}
	else if(argc == 2)
	{
//same as above except it checks it against an already arranged file
		file = argv[1];
//		checkfile(file.c_str());
		 ifstream infile;
                infile.open(file.c_str());
                string word;
                char a,b;
                while(infile >> word)
                {
		        int size=word.size();
                        char wordArray[size];
                        strcpy(wordArray,word.c_str());
                        int rslt = tree.searchTree(wordArray[size-1], tree.root, word);
                        count++;
                }
                infile.close();
		if (count == 0)
		{
			cout << "You must enter a file that is not empty" << endl;
			return -1;
		}
                int height=log(count)/log(2);
                cout << height << endl;
                levelorder(tree.root, "out.levelorder",height);
                preorder(tree.root, "out.preorder");
                inorder(tree.root, "out.inorder");

	}
	else if(argc <1 || argc > 3)
	{
		cout << "You have entered an invalid option please enter in form ./p0,./p0 < filename, or ./p0 filename" << endl;
		return 1;
	}
	else
	{
//final one is suppose to act as if they entered just ./p0 but redirects it to a certain file you typed, but for some
//reason its not working as intended.
		while ((ch = getopt(argc, argv, ":<")) !=-1)
		{
			switch(ch)
			{
				case '<':
					{
						file=argv[2];
						ofstream newfile;
						newfile.open(file.c_str());
						cout << "Enter data and press Ctrl+d on a new line to signal end of file when finished.\n";
                				int c;
                				char typedletters;
                				while ((c=getchar()) != EOF)
                				{
                				        typedletters=c;
                        				newfile << typedletters;
                				}
                				newfile.close();
						checkfile(file);
						ifstream infile;
				                infile.open(file.c_str());
				                string word;
				                char a,b;
				                while(infile >> word)
				                {

				                        int size=word.size();
				                        char wordArray[size];
				                        strcpy(wordArray,word.c_str());
				                        int rslt = tree.searchTree(wordArray[size-1], tree.root, word);
				                        count++;
				                }
				                infile.close();
				                if (count == 0)
				                {
				                        cout << "You must enter a file that is not empty" << endl;
				                        return -1;
				                }

						int height=log(count)/log(2);
				                cout << height << endl;
				                levelorder(tree.root, "out.levelorder",height);
				                preorder(tree.root, "out.preorder");
				                inorder(tree.root, "out.inorder");

					}
				default:
					printf("Wrong input please try again\n");
					exit(0);
			}
		}
	}
}
