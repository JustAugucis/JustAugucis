#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

ifstream rfM("Input.txt");
ifstream rf("Encryption.txt");
ofstream wf("Output.txt");
ifstream rfSpace("Space_bar.txt");
ifstream rfNext("Next_Letter.txt");

struct Encryption{
string letter[38];
string code[38];
int numberOfLetters;
string SpaceBar;
string spaceBetweenLetters;

};

void EncryptionReading(Encryption &Encryption); // reads ("Encryption.txt") and makes Encryption database
void Decoding(Encryption Encryption);
string reader();
void Write(string write);   //write with endl
void Write2(string write);  //write with out endl
void Encoding(Encryption Encryption);



int main()
{
    cout << "Creating database..." << endl;
    Encryption Encryption;
    cout << "Loading crypto protocol..." << endl;
    EncryptionReading(Encryption);
    cout << "Hello user, please choose function" << endl;
    cout << "1) Decoding" << endl;
    cout << "2) Encoding" << endl;
    int a;                              // for user input
    cin >> a;                           //getting user input
    if(a==1){Decoding(Encryption);}       // Function
    else if(a==2){Encoding(Encryption);}
    else{cout << "Error in making desicion" << endl;}

    cout << "Program finished" << endl;
    wf.close();
    return 0;
}
void EncryptionReading(Encryption &Encryption){ //Used for loading structure as database
        int c = 0; // Nesessary for putting information in different spots
        while(true){
            char x1;
            string x2;
            rf >> x1 >> x2;
            Encryption.letter[c] = x1;
            Encryption.code[c] = x2;
            //cout << c << " " << Encryption.letter[c] << " " << Encryption.code[c] << endl;    //Dispy of what is database loading
            if(rf.eof()){break;};
            c++;
        }
        Encryption.numberOfLetters = c;
        rfSpace >> Encryption.SpaceBar;
        rfNext >> Encryption.spaceBetweenLetters;

    rfNext.close();     //closes "Next_Letter.txt"
    rfSpace.close();    //closes "Space_bar.txt"
    rf.close();         //closes "Encryption.txt"
}
void Decoding(Encryption Encryption){

    while(!rfM.eof()){
    string line;
    line = reader();
    while(line.find(Encryption.SpaceBar)!= -1){line.replace(line.find(Encryption.SpaceBar),Encryption.SpaceBar.size()," ");}
    string ats; // Decrypted (line)
    string str; // Encrypted (line)
    while(!line.empty()){
            while(str.find(Encryption.spaceBetweenLetters)== -1 && line.size()!=0 && line.at(0)!= ' '){
                if(line.empty()){break;};
                if(line.at(0)== ' '){break;};
            str = str + line.at(0);
            line.erase(0,1);
            }
            if(str.find(Encryption.spaceBetweenLetters)!=-1)str.replace(str.find(Encryption.spaceBetweenLetters),Encryption.spaceBetweenLetters.size(),"");
            for(int c=0;Encryption.numberOfLetters>c;c++){
                if(Encryption.code[c]==str){ats = ats+Encryption.letter[c];}
            }
                if(line.size()!=0 && line.at(0)== ' '){ats = ats + ' ';line.erase(0,1);};
            str.erase();
    }
    Write(ats);
    }
    rfM.close();
    cout << "Check for output at local folder \"Output.txt\"  " << endl;
}
string reader(){
    string line;
        getline (rfM,line);
    return line;
}
void Write(string write){
    wf << write << endl;
}
void Write2(string write){
    wf << write;
}
void Encoding(Encryption Encryption){

    while(!rfM.eof()){
        string ats;     //Storing answer as line
        string letter;  //Storing letter
        string line;    //Storing a line
        line = reader();
        while(line.size()!=0){
            letter = line.at(0);
            line.erase(0,1);
        if(letter == " " ){ats = Encryption.SpaceBar;}
        else{for(int c=0;Encryption.numberOfLetters>c;c++){
            if(Encryption.letter[c]==letter){ats = Encryption.code[c];}}}
        Write2(ats);
        if(line.size()!=0 && line.at(0)!=' ' && letter!=" "){Write2(Encryption.spaceBetweenLetters);}

        }
        Write("");


    }

    rfM.close();
    cout << "Check for output at local folder \"Output.txt\"  " << endl;
}
