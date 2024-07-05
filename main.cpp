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

    string line;
    string currentLine;
    int pageNumber = 1;
    int lineCount = 0;

    while (inputFile >> line) {
         // Check if adding the next word exceeds the max line length
        if (currentLine.length() + line.length() + 1 > MAX_LINE_LENGTH) {
            // Output the current line and reset it
            outputFile << currentLine << endl;
            currentLine = line;
            lineCount++;
        } else {
            // Add the word to the current line
            if (!currentLine.empty()) {
                currentLine += " ";
            }
            currentLine += line;
        }

        // Check if the max lines per page is reached
        if (lineCount == MAX_LINES_PER_PAGE) {
            // Output the page separator
            outputFile << "=== Page " << pageNumber++ << " ===" << endl << endl;
            lineCount = 0;
        }
    }

    // Output any remaining text
    if (!currentLine.empty()) outputFile << currentLine << endl;
    
    // Output the final page number if there are any lines on the last page
    if (lineCount > 0) outputFile << "=== Page " << pageNumber << " ===" << endl << endl;

    // Close the input and output files
    inputFile.close();
    outputFile.close();
}


int main() {
    // Filenames for input and output files
    string inputFileName = "document.txt";
    string outputFileName = "output_document.txt";

    // Call the paginate function
    paginateDocument(inputFileName, outputFileName);

    // Notify the user of successful pagination
    cout << "Document paginated successfully!" << endl;

    return 0;
}