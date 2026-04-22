#include <iostream>
#include <string>
using namespace std;

const int n = 100;
string titles[n] = {
"The Great Gatsby","To Kill a Mockingbird","1984","Pride and Prejudice","Moby-Dick",
"War and Peace","The Catcher in the Rye","The Hobbit","Brave New World","Crime and Punishment",
"Jane Eyre","The Lord of the Rings","Animal Farm","Wuthering Heights","The Odyssey",
"The Brothers Karamazov","One Hundred Years of Solitude","The Picture of Dorian Gray","Fahrenheit 451","Dracula",
"The Iliad","Les Miserables","A Tale of Two Cities","Don Quixote","Ulysses",
"The Divine Comedy","Hamlet","Macbeth","The Alchemist","The Little Prince",
"Slaughterhouse-Five","Catch-22","The Sun Also Rises","The Old Man and the Sea","Anna Karenina",
"Madame Bovary","The Stranger","The Metamorphosis","Siddhartha","Heart of Darkness",
"The Sound and the Fury","Lolita","Beloved","Invisible Man","The Road",
"Life of Pi","The Kite Runner","A Thousand Splendid Suns","The Book Thief","The Fault in Our Stars",
"Gone with the Wind","The Hunger Games","Harry Potter and the Sorcerers Stone","The Da Vinci Code","Angels and Demons",
"The Girl with the Dragon Tattoo","The Shining","It","Misery","Dune",
"Enders Game","Neuromancer","Snow Crash","Foundation","I, Robot",
"The Martian","Ready Player One","Jurassic Park","The Time Machine","The War of the Worlds",
"Frankenstein","The Handmaids Tale","Oryx and Crake","The Giver","The Maze Runner",
"Divergent","Twilight","The Chronicles of Narnia","Alices Adventures in Wonderland","Through the Looking Glass",
"Peter Pan","Treasure Island","Robinson Crusoe","Gullivers Travels","The Secret Garden",
"Little Women","Anne of Green Gables","Heidi","Black Beauty","Charlottes Web",
"Matilda","The BFG","Charlie and the Chocolate Factory","The Wind in the Willows","Watership Down","The Grapes of Wrath","East of Eden","The Old Man and the Sea","The Name of the Rose","Foundation"
};

string authors[n] = {
"F. Scott Fitzgerald","Harper Lee","George Orwell","Jane Austen","Herman Melville",
"Leo Tolstoy","J.D. Salinger","J.R.R. Tolkien","Aldous Huxley","Fyodor Dostoevsky",
"Charlotte Bronte","J.R.R. Tolkien","George Orwell","Emily Bronte","Homer",
"Fyodor Dostoevsky","Gabriel Garcia Marquez","Oscar Wilde","Ray Bradbury","Bram Stoker",
"Homer","Victor Hugo","Charles Dickens","Miguel de Cervantes","James Joyce",
"Dante Alighieri","William Shakespeare","William Shakespeare","Paulo Coelho","Antoine de Saint-Exupery",
"Kurt Vonnegut","Joseph Heller","Ernest Hemingway","Ernest Hemingway","Leo Tolstoy",
"Gustave Flaubert","Albert Camus","Franz Kafka","Hermann Hesse","Joseph Conrad",
"William Faulkner","Vladimir Nabokov","Toni Morrison","Ralph Ellison","Cormac McCarthy",
"Yann Martel","Khaled Hosseini","Khaled Hosseini","Markus Zusak","John Green",
"Margaret Mitchell","Suzanne Collins","J.K. Rowling","Dan Brown","Dan Brown",
"Stieg Larsson","Stephen King","Stephen King","Stephen King","Frank Herbert",
"Orson Scott Card","William Gibson","Neal Stephenson","Isaac Asimov","Isaac Asimov",
"Andy Weir","Ernest Cline","Michael Crichton","H.G. Wells","H.G. Wells",
"Mary Shelley","Margaret Atwood","Margaret Atwood","Lois Lowry","James Dashner",
"Veronica Roth","Stephenie Meyer","C.S. Lewis","Lewis Carroll","Lewis Carroll",
"J.M. Barrie","Robert Louis Stevenson","Daniel Defoe","Jonathan Swift","Frances Hodgson Burnett",
"Louisa May Alcott","L.M. Montgomery","Johanna Spyri","Anna Sewell","E.B. White",
"Roald Dahl","Roald Dahl","Roald Dahl","Kenneth Grahame","Richard Adams", "John Steinbeck","John Steinbeck","Ernest Hemingway","Umberto Eco","Isaac Asimov"
};

bool taken[n] = {false};

void sortBooks(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(titles[j] > titles[j+1]){

                string temp = titles[j];
                titles[j] = titles[j+1];
                titles[j+1] = temp;

                temp = authors[j];
                authors[j] = authors[j+1];
                authors[j+1] = temp;

                bool t = taken[j];
                taken[j] = taken[j+1];
                taken[j+1] = t;
            }
        }
    }
}

void borrowBook(string title, string author){
    for(int i=0; i<n; i++){
        if(titles[i]==title && authors[i]==author){

            if(!taken[i]){
                taken[i]=true;
                cout << "Taken: " << titles[i] << " - " << authors[i] << endl;
            } else {
                cout << "Already taken" << endl;
            }
            return;
        }
    }
    cout << "Not found" << endl;
}


void returnBook(string title, string author){
    for(int i=0;i<n;i++){
        if(titles[i]==title && authors[i]==author){

            if(taken[i]){
                taken[i] = false;
                cout <<"Returned: " << titles[i] << " - "<< authors[i]<< endl;
            } else {
                cout <<"Was not taken" << endl;
            }
            return;
        }
    }
    cout <<"Not found" <<endl;
}


void bookReport(bool takenBook){
    bool isBook = false;
    for(int i = 0; i < n; i++){
        if(taken[i] == takenBook){
            cout << titles[i]<<" - "<<authors[i]<<endl;
            isBook = true;
        }
    }
    if(!isBook)
    cout << "No books." <<endl;
}


int main(){
    
    sortBooks();
    string cmd, title, author;
    while(true){

        cout << "Enter command (borrow / return / taken / remaining). "<<endl;
        getline(cin, cmd);

        if(cmd == "taken"){
            bookReport(true);
        }
        
        else if(cmd == "remaining"){
            bookReport(false);
        }
        
        else if(cmd == "borrow"){
            cout << "Enter book title: ";
            getline(cin, title);

            cout << "Enter author: ";
            getline(cin, author);

            borrowBook(title, author);
        }
        
        else if(cmd == "return"){

            cout << "Enter book title: ";
            getline(cin, title);

            cout << "Enter author: ";
            getline(cin, author);

            returnBook(title, author);
        }
        
        else{
            cout << "Unknown command"<<endl;
        }
    }
}
