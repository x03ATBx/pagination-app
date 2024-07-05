#include <iostream>
#include <fstream>
using namespace std;

// Constants for the maximum line length and the maximum number of lines per page
const int MAX_LINE_LENGTH = 80;
const int MAX_LINES_PER_PAGE = 25;

// Function to paginate a document
// Paginates the document in the input file and writes the paginated document to the output file
// Input: inputFileName - the name of the input file
//        outputFileName - the name of the output file
void paginateDocument(const string& inputFileName, const string& outputFileName) {

    // Open the input file
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file" << endl;
        return;
    }

    // Open the output file
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file" << endl;
        return;
    }

    string word;
    string currentLine;
    int pageNumber = 1;
    int lineCount = 0;

    while (inputFile >> word) {
        // Check if adding the next word exceeds the max line length
        if (currentLine.length() + word.length() >= MAX_LINE_LENGTH) {
            // Output the current line and reset it
            outputFile << currentLine << endl;
            currentLine = word;
            lineCount++;
        } else {
            // Add the word to the current line
            if (!currentLine.empty()) {
                currentLine += " ";
            }
            currentLine += word;
        }

        // Check if the max lines per page is reached
        if (lineCount == MAX_LINES_PER_PAGE) {
            // Output the page separator
            outputFile << "=== Page " << pageNumber++ << " ===" << endl << endl;
            lineCount = 0;
        }
    }

    // Output any remaining text
    if (!currentLine.empty()) {
        outputFile << currentLine << endl;

        // Output the final page number
        outputFile << "=== Page " << pageNumber << " ===" << endl;
    }
    
    // Close the input and output files
    inputFile.close();
    outputFile.close();

    // Notify the user of successful pagination
    cout << "Document paginated successfully!" << endl;
}


int main() {
    // Filenames for input and output files
    string inputFileName = "document.txt";
    string outputFileName = "output_document.txt";

    // Call the paginate function
    paginateDocument(inputFileName, outputFileName);

    return 0;
}