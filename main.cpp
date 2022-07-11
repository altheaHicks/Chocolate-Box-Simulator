/* 
*  Name: Althea Leigh Hicks 
*  Description: A program that simulates pulling chocolates out of a box
*/ 

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
/* 
*  chocolate: parent class that holds virtual function
*  constructors: none
*  public  functions:  virtual string wahtamI()
*  static members: none
*/ 
class chocolate{

    public:
     virtual string whatamI()=0;
};
/* 
*  dark: class that describes dark chocolate type
*  constructors: none
*  public  functions: string whatamI(), void feelBitter()
*  static members: none
*/ 
class dark : public chocolate {

    public: 
    string whatamI(){
        string dark = "dark";
        return dark;
    }
    void feelBitter(){ 
        cout << "Dark Chocolate: oof that was bitter!" << endl;
        cout << endl; 
    } 
};
/* 
*  milk: class that describes milke chocolate type
*  constructors: none
*  public  functions: whatamI(), feelSoft()
*  static members: none
*/ 
class milk : public chocolate {

    public:
    string whatamI(){
        string milk = "milk";
        return milk;
    }
    void feelSoft(){ 
        cout << "Milk Chocolate: Too soft, no chocolate taste!" << endl; 
        cout << endl;
    } 
};
/* 
*  hazelnut:  class that describes hazelnut chocolate type
*  constructors: none
*  public  functions:  whatamI(), getAllergy() 
*  static members: none
*/ 
class hazelnut : public chocolate {

    public:
    string whatamI(){
        string hazelnut = "hazelnut";
        return hazelnut;
    }
    void getAllergy(){ 
        cout << "Hazelnut Chocolate: I don't feel so good." << endl; 
        cout << endl;
    } 
};
/* 
*  raspberry: class that describes raspeberry chocolate type
*  constructors: none
*  public  functions: whatamI(), telljoke()
*  static members: none
*/ 
class raspberry : public chocolate {

    public:
    string whatamI(){
        string raspberry = "raspberry";
        return raspberry;
    }
    void telljoke(){ 
        cout << "Raspberry Chocolate: I don't always Raspberry," 
             << " but when I do, I Raspberry Pi" << endl; 
        cout << endl;
    } 
};
/* 
*  white: class that describes white chocolate type
*  constructors: none
*  public  functions:  whatamI(), feelScammed()
*  static members: none
*/ 
class white : public chocolate {

    public:
    string whatamI(){
        string white = "white";
        return white;
    }
    void feelScammed(){ 
        cout << "White Chocolate: Is this even real chocolate?" << endl; 
        cout << endl;
    } 
};
/* 
*  mint: class that describes mint chocolate type
*  constructors: none 
*  public  functions: whatamI(), feelINsquisitive()
*  static members: none
*/ 
class mint : public chocolate {

    public:
    string whatamI(){
        string mint = "mint";
        return mint;
    }
    void feelInquisitive(){ 
        cout << "Mint Chocolate: Am I still eating chocolate" 
             << " or am I brushing my teeth?" << endl; 
        cout << endl;
    } 
};
/* 
*  boxOfChocolates:  class that creates box,and selects chocolates
*  constructors: boxOfChocolates(int, int)
*  public  functions:  fillBox()
*                      bool takeChocolate()
*  static members: none
*  (    int boxLength;int boxWidth;string** box;) 
*/ 
class boxOfChocolates{
    private:
    int boxLength;
    int boxWidth;
    string** box;

    public:

    boxOfChocolates(int defaultLength = 6, int defaultWidth = 5){
        boxLength = defaultLength;
        boxWidth = defaultWidth;
        box = new string*[boxLength];
        for(int i = 0; i < boxLength; i++){
            box[i] = new string[boxWidth];
        }
        fillBox();
    };
    ~boxOfChocolates(){
        for(int i = 0; i < boxLength; i++){
            delete[] box[i];
        }
        delete[] box;
        box = NULL;
    };
    void fillBox(){

        dark* darkPtr = new dark;
        milk* milkPtr = new milk;
        hazelnut* hazelPtr = new hazelnut;
        raspberry* raspPtr = new raspberry;
        white* whitePtr = new white;
        mint* mintPtr = new mint;

        for( int i=0; i<boxLength;i++ ){
            for( int j=0; j<boxWidth;j++ ){
                int randomNum = rand()%6;
                switch(randomNum){
                    case 0:
                    box[i][j] = darkPtr->whatamI();
                    break;
                    case 1:
                    box[i][j] = milkPtr->whatamI();
                    break;
                    case 2:
                    box[i][j] = hazelPtr->whatamI();
                    break;
                    case 3:
                    box[i][j] = raspPtr->whatamI();
                    break;
                    case 4:
                    box[i][j] = whitePtr->whatamI();
                    break;
                    case 5:
                    box[i][j] = mintPtr->whatamI();
                    break;
                    //default
                    default:
                    break;
                }
            }
        }
        delete darkPtr; //delete pointers
        delete milkPtr;
        delete hazelPtr;
        delete raspPtr;
        delete whitePtr;
        delete mintPtr;
    };
    bool takeChocolate(){
        int randLength = rand()%6;
        int randWidth = rand()%5;
        string typeOfChoc;

        dark* darkPtr = new dark;
        milk* milkPtr = new milk;
        hazelnut* hazelPtr = new hazelnut;
        raspberry* raspPtr = new raspberry;
        white* whitePtr = new white;
        mint* mintPtr = new mint;

        typeOfChoc = box[randLength][randWidth];
        if(typeOfChoc == "dark"){
            darkPtr->feelBitter();
            box[randLength][randWidth] = "";
            delete darkPtr;
            delete milkPtr;
            delete hazelPtr;
            delete raspPtr;
            delete whitePtr;
            delete mintPtr;
            return true;
        }
        else if(typeOfChoc == "milk"){
            milkPtr->feelSoft();
            box[randLength][randWidth] = "";
            delete darkPtr;
            delete milkPtr;
            delete hazelPtr;
            delete raspPtr;
            delete whitePtr;
            delete mintPtr;
            return true;
        }
        else if(typeOfChoc == "hazelnut"){
            hazelPtr->getAllergy();
            box[randLength][randWidth] = "";
            delete darkPtr;
            delete milkPtr;
            delete hazelPtr;
            delete raspPtr;
            delete whitePtr;
            delete mintPtr;
            return true;
        }
        else if(typeOfChoc == "raspberry"){
            raspPtr->telljoke();
            box[randLength][randWidth] = "";
            delete darkPtr;
            delete milkPtr;
            delete hazelPtr;
            delete raspPtr;
            delete whitePtr;
            delete mintPtr;
            return true;
        }
        else if(typeOfChoc == "white"){
            whitePtr->feelScammed();
            box[randLength][randWidth] = "";
            delete darkPtr;
            delete milkPtr;
            delete hazelPtr;
            delete raspPtr;
            delete whitePtr;
            delete mintPtr;
            return true;
        }
        else if(typeOfChoc == "mint"){
            mintPtr->feelInquisitive();
            box[randLength][randWidth] = "";
            delete darkPtr;
            delete milkPtr;
            delete hazelPtr;
            delete raspPtr;
            delete whitePtr;
            delete mintPtr;
            return true;
        }
        else{
            delete darkPtr; //delete pointers
            delete milkPtr;
            delete hazelPtr;
            delete raspPtr;
            delete whitePtr;
            delete mintPtr;
            return false;
        }
    };
};
int main(int argc, char **argv){

    //error check second argument
    if(argc<2){
        cout << "Error, please enter a seed value as second argument. i.e. ' ./a.out  42 ' " << endl;
        return 0;
    }

    //Convert seed from command line argument into an integer
    string seedString = argv[1];
    int seedInt = stoi(seedString);

    //call seed function
    srand(seedInt);

    //print headers sentence
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "My mom always said \"life was like a box of chocolates. You never know what you're gonna get.\" - Forrest Gump" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    //create boxOfChocolates object
    boxOfChocolates carpeDiem;
    
    //go through takeChocolate() function until it returns false
    while(carpeDiem.takeChocolate() == true){
    }
    return 0;
}
