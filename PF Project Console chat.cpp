//// Include required header files
//#include <iostream>   // For input and output (cout, cin)
//#include <string>     // For using string data type
//#include <cctype>     // For character handling functions like tolower()
//using namespace std;  // Use the standard namespace to avoid writing std:: repeatedly
//
//// ----------------------------
//// Base Class: ChatUser
//// ----------------------------
//class ChatUser {
//protected:
//    string name;  // Stores the name of the user or chatbot
//public:
//    // Constructor: initializes the name of the chat participant
//    ChatUser(string n) : name(n) {}
//
//    // Pure virtual function - makes this class abstract
//    // Derived classes must define their own sendMessage() method
//    virtual void sendMessage(string msg) = 0;
//
//    // Getter function to return the name
//    string getName() { return name; }
//};
//
//// ----------------------------
//// Derived Class: User
//// Represents the human user
//// ----------------------------
//class User : public ChatUser {
//public:
//    // Constructor: passes the user name to the base class constructor
//    User(string n) : ChatUser(n) {}
//
//    // Override sendMessage() to print the user's message
//    void sendMessage(string msg) override {
//        cout << name << ": " << msg << endl;  // Example: Sarmad: hello
//    }
//};
//
//// ----------------------------
//// Derived Class: ChatBot
//// Represents the chatbot system
//// ----------------------------
//class ChatBot : public ChatUser {
//public:
//    // Constructor: passes the bot name to the base class constructor
//    ChatBot(string n) : ChatUser(n) {}
//
//    // Override sendMessage() to print bot's reply with "(Bot)" label
//    void sendMessage(string msg) override {
//        cout << name << " (Bot): " << msg << endl;  // Example: SmartBot (Bot): Hello!
//    }
//
//    // Function to generate a reply based on user input
//    string generateReply(string userMessage) {
//        // Convert the user message to lowercase to make matching easier
//        for (auto &c : userMessage)
//            c = tolower(c);
//
//        // Compare the user's message with known commands and return replies
//        if (userMessage == "hi" || userMessage == "hello")
//            return "Hello there! How can I assist you today?";
//        else if (userMessage == "how are you")
//            return "I'm just a bot, but I'm feeling efficient today!";
//        else if (userMessage == "what is your name")
//            return "I'm SmartBot, created using C++ OOP concepts.";
//        else if (userMessage == "help")
//            return "You can ask me simple questions or type 'bye' to exit.";
//        else if (userMessage == "bye")
//            return "Goodbye! Have a great day!";
//        else
//            // Default reply for unknown input
//            return "Sorry, I didn't understand that. Please try again.";
//    }
//};
//
//// ----------------------------
//// Main Function: Program Entry Point
//// ----------------------------
//int main() {
//    string userName;  // Variable to store the user's name
//
//    // Ask for the user's name
//    cout << "Enter your name: ";
//    getline(cin, userName);  // Get full name input (including spaces)
//
//    // Create objects for User and ChatBot classes
//    User user(userName);        // User object with entered name
//    ChatBot bot("SmartBot");    // ChatBot object with fixed name
//
//    cout << "\n--- Chat Started ---" << endl;
//
//    // Infinite loop for continuous chat until the user says "bye"
//    while (true) {
//        string userMsg;  // To store user's message
//
//        // Display user name and get input
//        cout << user.getName() << ": ";
//        getline(cin, userMsg);
//
//        // Show user message
//        user.sendMessage(userMsg);
//
//        // Generate chatbot reply based on user input
//        string reply = bot.generateReply(userMsg);
//
//        // Display chatbot reply
//        bot.sendMessage(reply);
//
//        // Exit condition - if the user says "bye", break out of loop
//        if (userMsg == "bye")
//            break;
//    }
//
//    // Display end message
//    cout << "--- Chat Ended ---" << endl;
//
//    // Exit the program
//    return 0;
//}




#include <iostream> // Provides input and output functionality in C++

#include <string> // Enables the use of the std::string class, which
                  // makes working with text easier than using C-style character arrays.
                        
#include <algorithm> // Contains a large collection of general-purpose algorithms
                     // that operate on containers (like arrays, vectors, strings).

std::string toLower(const std::string &s) {
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(), ::tolower);
    return out;
}

#ifdef _WIN32 // _WIN32 is a predefined macro in most C++ compilers that is automatically
              // defined when compiling on Windows (both 32-bit and 64-bit).
              
#include <windows.h> // This header is specific to Windows.
                     // It allows your program to use Windows API functions.

#endif // Used to close a preprocessor conditional 
       //directive that was opened with #ifdef, #ifndef, or #if.

int main() {
    std::cout << "Chatbot: Hello! I'm a simple console chatbot. Type 'exit' to quit.\n";

    while (true) {
        std::cout << "You: ";
        std::string input;
        std::getline(std::cin, input);

        std::string lower = toLower(input);
        if (lower == "exit") {
            std::cout << "Chatbot: Goodbye!" << std::endl;
            break;
        }

        if (lower.find("hello") != std::string::npos || lower.find("hi") != std::string::npos) {
            std::cout << "Chatbot: Hi there! How can I help you today?\n";
        } else if (lower.find("how are you") != std::string::npos) {
            std::cout << "Chatbot: I'm just code, but I'm running great!\n";
        } else if (lower.find("name") != std::string::npos) {
            std::cout << "Chatbot: I'm ConsoleBot, nice to meet you!\n";
        } else if (lower.find("help") != std::string::npos) {
            std::cout << "Chatbot: You can greet me, ask my name, or type 'exit' to leave.\n";
        } else if (lower.find("weather") != std::string::npos) {
            std::cout << "Chatbot: I can't check the weather, but I hope it's nice where you are!\n";
        } else if (lower.find("time") != std::string::npos) {
            std::cout << "Chatbot: I don't have a clock, but it's always a good time to code!\n";
        } else if (lower.find("joke") != std::string::npos) {
            std::cout << "Chatbot: Why do programmers hate nature? Too many bugs!\n";
        
        } else if (lower.find("open chrome") != std::string::npos) {
            system("start chrome");
            std::cout << "Chatbot: Opening Chrome...\n";
        } else if (lower.find("open youtube") != std::string::npos) {
            system("start https://www.youtube.com");
            std::cout << "Chatbot: Opening YouTube...\n";
        } else if (lower.find("open time") != std::string::npos || lower.find("show time") != std::string::npos) {
#ifdef _WIN32
            system("start timedate.cpl");
#endif
            std::cout << "Chatbot: Showing system time...\n";
        } else {
            std::cout << "Chatbot: I'm not sure how to respond to that yet.\n";
        }
    }

    return 0;
}

