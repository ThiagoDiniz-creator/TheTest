//

#include <string>
#include <iostream>

void PrintIntroduction(){
        //The introduction text
        std::cout << "You entered the challenge to qualify for the International Code Academy \n";
        std::cout << "Solve the following ten problems, if you guess them all correctly you are approved \n";
}

void PrintQuestion(int CodeSum, int CodeProduct, int QuestionNumber){
        std::cout << "----------------------------------- \n";
        std::cout << "            Question " << QuestionNumber + 1 << "           \n";
        std::cout << "There are three numbers that are part of a code, ";
        std::cout << "these numbers add up to: "<< CodeSum << std::endl;
        std::cout << "and the product of the code is: " << CodeProduct << std::endl;
        std::cout << "Insert the value of each one of the three numbers (separated by one space, example: 3 2 1): \n";
}

bool PlayGame(int Difficulty){

        //Reseting the random sequences
        srand(time(0));

        //Declare three numbers that are part of the code using a random generator
        int NumberA = (1 + Difficulty) + (rand() % (3 + (3 * Difficulty)));
        int NumberB = (1 + Difficulty) + (rand() % (3 + (3 * Difficulty)));
        int NumberC = (1 + Difficulty) + (rand() % (3 + (3 * Difficulty)));

        //Calculate the sum and the product of the said numbers
        int CodeSum = NumberA + NumberB + NumberC;
        int CodeProduct = NumberA * NumberB * NumberC;

        PrintQuestion(CodeSum, CodeProduct, Difficulty);

        //Store the player's input
        int InputA, InputB, InputC;
        std::cin >> InputA >> InputB >> InputC;

        //Calculate the sum and the product of the inputs
        int InputSum = InputA + InputB + InputC;
        int InputProduct = InputA * InputB * InputC;

        if(InputSum == CodeSum && InputProduct == CodeProduct){
            std::cout << std::endl << "Congratulations you are right \n";
            return true;
        }else{
            std::cout << std::endl << "Oh, you are wrong \n";
            std::cout << "The correct answer is: " << NumberA << " " << NumberB << " " <<NumberC << "\n";
            return false;
        };
};  

int main(){

    PrintIntroduction();//Prints the introduction text
    
    bool bContinue = true;

    for(int i = 0; i < 11 && bContinue; i++){
        bContinue = PlayGame(i);

        std::cin.clear();//Clear any error
        std::cin.ignore();//Discards the buffer so any problem doesn't persist

    }

    if(bContinue){
        std::cout << "\n Congratulations you passed the test, welcome to the International Code Academy \n";
    }

};