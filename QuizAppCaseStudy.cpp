#include <iostream>
#include <string>

using namespace std;

int main() {
    int score = 0;

    // Welcome interface and instructions
    cout << "\nWelcome to the History of India Quiz!\n"
         << "You'll be asked 5 questions about Indian history.\n"
         << "Choose the correct answer from the given options.\n\n";

    // Define the questions, options, and correct answers
    string questions[5] = {
        "1. Who was the founder of the Gupta Empire?",
        "2. Which Mughal emperor built the Taj Mahal?",
        "3. In what year did India gain independence from British rule?",
        "4. Who was the first Prime Minister of India?",
        "5. What is the national flower of India?"
    };
    string options[5][4] = {
        {"a. Chandragupta I", "b. Samudragupta", "c. Ashoka", "d. Harsha"},
        {"a. Akbar", "b. Shah Jahan", "c. Jahangir", "d. Aurangzeb"},
        {"a. 1947", "b. 1950", "c. 1965", "d. 1971"},
        {"a. Mahatma Gandhi", "b. Jawaharlal Nehru", "c. Indira Gandhi", "d. Sardar Patel"},
        {"a. Lotus", "b. Rose", "c. Sunflower", "d. Marigold"}
    };
    char correctAnswers[5] = {'a', 'b', 'a', 'b', 'a'};

    // Ask the questions and check the answers
    for (int i = 0; i < 5; i++) {
        cout << questions[i] << endl;
        for (int j = 0; j < 4; j++) {
            cout << options[i][j] << endl;
        }

        char userAnswer;
        cout << "Enter your answer (a, b, c, or d): ";
        cin >> userAnswer;

        if (userAnswer == correctAnswers[i]) {
            score++;
            cout << "Correct!\n";
        } else {
            cout << "Incorrect. The correct answer is " << correctAnswers[i] << ".\n";
        }
        cout << endl; // Add a blank line between questions
    }

    // Display the final score
    cout << "\nYour final score is: " << score << " out of 5.\n"
         << "Thank you for playing!\n";

    return 0;
}
