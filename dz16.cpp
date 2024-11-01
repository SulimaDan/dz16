#include <iostream>
#include <string>


void addColumn(int**& array, int rows, int& cols, int position) {
    int** newArray = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        newArray[i] = new int[cols + 1];
        for (int j = 0, k = 0; j < cols + 1; ++j) {
            if (j == position) {
                newArray[i][j] = 0; 
            }
            else {
                newArray[i][j] = array[i][k++];
            }
        }
    }
    for (int i = 0; i < rows; ++i) delete[] array[i];
    delete[] array;
    array = newArray;
    ++cols;
}


void deleteColumn(int**& array, int rows, int& cols, int position) {

    int** newArray = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        newArray[i] = new int[cols - 1];
        for (int j = 0, k = 0; j < cols; ++j) {
            if (j != position) {
                newArray[i][k++] = array[i][j];
            }
        }
    }
    for (int i = 0; i < rows; ++i) delete[] array[i];
    delete[] array;
    array = newArray;
    --cols;
}


void shiftRows(int** array, int rows, int cols, int times, bool right) {
    times %= rows; 
    if (right) {
        for (int t = 0; t < times; ++t) {
            int* lastRow = array[rows - 1];
            for (int i = rows - 1; i > 0; --i) {
                array[i] = array[i - 1];
            }
            array[0] = lastRow;
        }
    }
    else {
        for (int t = 0; t < times; ++t) {
            int* firstRow = array[0];
            for (int i = 0; i < rows - 1; ++i) {
                array[i] = array[i + 1];
            }
            array[rows - 1] = firstRow;
        }
    }
}



int** transposeMatrix(int** matrix, int rows, int cols) {
    int** transposed = new int* [cols];
    for (int i = 0; i < cols; ++i) {
        transposed[i] = new int[rows];
        for (int j = 0; j < rows; ++j) {
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}









struct Contact {
    std::string name;
    std::string phone;
};

void addContact(Contact*& contacts, int& size, const std::string& name, const std::string& phone) {
    Contact* newContacts = new Contact[size + 1];
    for (int i = 0; i < size; ++i) {
        newContacts[i] = contacts[i];
    }
    newContacts[size] = { name, phone };
    delete[] contacts; 
    contacts = newContacts;
    ++size;
}

int searchByName(Contact* contacts, int size, const std::string& name) {
    for (int i = 0; i < size; ++i) {
        if (contacts[i].name == name) {
            return i; 
        }
    }
    return -1; 
}

int searchByPhone(Contact* contacts, int size, const std::string& phone) {
    for (int i = 0; i < size; ++i) {
        if (contacts[i].phone == phone) {
            return i; 
        }
    }
    return -1; 
}

void modifyContact(Contact* contacts, int index, const std::string& newName, const std::string& newPhone) {
    if (index >= 0) {
        contacts[index].name = newName;
        contacts[index].phone = newPhone;
    }
}

int main() {
    Contact* contacts = nullptr; 
    int size = 0;

    addContact(contacts, size, "Dan", "123456789");
    addContact(contacts, size, "Siuhy", "987654321");

    int index = searchByName(contacts, size, "Dan");
    if (index != -1) {
        std::cout << "Found Dan at index " << index << ": " << contacts[index].phone << std::endl;
    }

    modifyContact(contacts, index, "Dan", "111222333");
    std::cout << "Dan new phone: " << contacts[index].phone << std::endl;

    delete[] contacts;
    return 0;
}

