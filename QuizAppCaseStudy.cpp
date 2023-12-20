#include <iostream>
#include <string>
#include <map>

using namespace std;

class HistoryQuiz {
private:
    map<string, pair<string, string>> questions;
    int score;
    map<string, bool> questionStatus;  // To track whether a question has been asked

public:
    HistoryQuiz() : score(0) {
        initializeQuestions();
    }

    void initializeQuestions() {
        // Add questions and answers
        cout<<endl;
        questions["1"] = make_pair("Who was the first Emperor of the Maurya Dynasty in ancient India?", "a. Chandragupta Maurya   b. Ashoka   c. Bindusara   d. Akbar");
        questions["2"] = make_pair("In which year did India gain independence?", "a. 1947   b. 1950   c. 1942   d. 1930");
        questions["3"] = make_pair("Who was the founder of the Gupta Empire?", "a. Chandragupta I   b. Samudragupta   c. Ashoka   d. Harsha");
        questions["4"] = make_pair("Which Indian river is considered sacred in Hinduism?", "a. Ganges   b. Yamuna   c. Brahmaputra   d. Godavari");
        questions["5"] = make_pair("Who was known as the 'Father of the Indian Constitution'?", "a. B.R. Ambedkar   b. Sardar Patel   c. Jawaharlal Nehru   d. Mahatma Gandhi");
        // Add more questions in a similar manner

        // Initialize question status
        for (const auto& questionPair : questions) {
            questionStatus[questionPair.first] = false;
        }
    }

    void displayQuestion(const string& questionID) {
        cout << questions[questionID].first << endl;
        cout << questions[questionID].second << endl;
    }

    bool isAnswerCorrect(const string& questionID, const string& userAnswer) {
        return userAnswer == questions[questionID].second.substr(0, 1);
    }

    void startQuiz() {
        cout << "===============================================" << endl;
        cout << "=== Welcome to the History Quiz about India ===" << endl;
        cout << "===============================================" << endl;
        cout << "===============================================" << endl;
        cout << "Instructions: Select the correct option (a, b, c, or d) for each question." << endl;
        cout << "================================================" << endl;

        for (const auto& questionPair : questions) {
            string questionID = questionPair.first;

            if (!questionStatus[questionID]) {
                displayQuestion(questionID);

                string userAnswer;
                cout << "Your answer (type 'exit' to end the quiz): ";
                cin >> userAnswer;

                if (userAnswer == "exit") {
                    break; // Exit the loop if the user wants to end the quiz
                }

                if (isAnswerCorrect(questionID, userAnswer)) {
                    cout << "Correct!" << endl;
                    score++;
                } else {
                    cout <<endl<< "Incorrect. The correct answer is: " << getCorrectAnswer(questionID) << endl;
                }

                questionStatus[questionID] = true;  // Mark the question as asked
                cout << "------------------------" << endl;
            }
        }

        cout << "Quiz completed. Your final score: " << score << "/" << questions.size() << endl;
    }

    string getCorrectAnswer(const string& questionID) {
        return questions[questionID].second.substr(0, 1);
    }
};

int main() {
    HistoryQuiz quiz;
    quiz.startQuiz();

    return 0;
}
