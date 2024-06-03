#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h> // For sleep function
using namespace std;




class User {
public:
    string username;
    string password;

    User(string uname, string pwd) : username(uname), password(pwd) {}

    bool authenticate(string uname, string pwd) {
        return (username == uname && password == pwd);
    }
};

// Class worker
class worker {
protected:
    int age, CNIC, ID, genderr, mobile_no;
    string name, address, status;

public:
    // Constructor
    worker() {
        name = "NO NAME";
        address = "NO ADDRESS";
        age = 0;
        CNIC = 0;
        ID = 0;
        genderr = 0;
        status = "NO status";
        mobile_no = 0;
    }

    // Setters and Getters
    void setName(string n) { name = n; }
    string getName() { return name; }

    void setAge(int a) { age = a; }
    int getAge() { return age; }

    void setCniC(int cnic) { CNIC = cnic; }
    int getCniC() { return CNIC; }

    void setNo(int num) { mobile_no = num; }
    int getNO() { return mobile_no; }

    void setAddress(string add) { address = add; }
    string getAddress() { return address; }

    void setSTATUS(string st) { status = st; }
    string getSTATUS() { return status; }

    void setgend(int se) { genderr = se; }
    int getgend() { return genderr; }

    // Function to enter worker details
    void entery() {
        
        cout << "Enter Worker name: ";
        cin >> name;
        cout << "Enter Worker age: ";
        cin >> age;
        cout << "Enter Worker mobile number: ";
        cin >> mobile_no;
        cout << "Enter Worker CNIC number: ";
        cin >> CNIC;
        cout << "Enter Worker address: ";
        cin >> address;
        cout << "Enter Worker status: ";
        cin >> status;

        string gender[4] = {"Male", "Female", "Custom", "Prefer not to say"};
        cout << "Worker Gender:\t   1.Male\t  2.Female\t3.Custom\t4.Prefer not to say" << endl;
        cout << "Enter: ";
        cin >> genderr;

        if (genderr >= 1 && genderr <= 4) {
            cout << "Your Gender is: " << gender[genderr - 1] << endl;
        } else {
            cout << "INVALID!!" << endl;
        }

        ofstream on("worker.txt");
        on << "Name: " << name << endl;
        on << "Age: " << age << endl;
        on << "Mobile No: " << mobile_no << endl;
        on << "CNIC: " << CNIC << endl;
        on << "Address: " << address << endl;
        on << "Status: " << status << endl;
        on << "Gender: " << gender[genderr - 1] << endl;
    }
};

// Class Parking
class Parking {
private:
    int totalSpots;
    int availableSpots;
    string* parkedVehicles;
    int* occupied; // Array to track occupied spots (1 for occupied, 0 for free)

public:
    // Constructor
    Parking(int total) : totalSpots(total), availableSpots(total) {
        parkedVehicles = new string[total];
        occupied = new int[total];
        for (int i = 0; i < total; ++i) {
            occupied[i] = 0; // Initialize all spots as free
        }
    }

    // Destructor
    ~Parking() {
        delete[] parkedVehicles;
        delete[] occupied;
    }

    // Method to park a vehicle
    bool parkVehicle(const string& vehicle) {
        if (availableSpots > 0) {
            for (int i = 0; i < totalSpots; ++i) {
                if (occupied[i] == 0) {
                    parkedVehicles[i] = vehicle;
                    occupied[i] = 1;
                    availableSpots--;
                    cout << "Vehicle " << vehicle << " parked successfully at spot " << i + 1 << ".\n";
                    return true;
                }
            }
        } else {
            cout << "Parking is full. Cannot park vehicle " << vehicle << ".\n";
            return false;
        }
        return false;
    }

    // Method to remove a vehicle
    bool removeVehicle(const string& vehicle) {
        for (int i = 0; i < totalSpots; ++i) {
            if (occupied[i] == 1 && parkedVehicles[i] == vehicle) {
                parkedVehicles[i] = "";
                occupied[i] = 0;
                availableSpots++;
                cout << "Vehicle " << vehicle << " removed successfully from spot " << i + 1 << ".\n";
                return true;
            }
        }
        cout << "Vehicle " << vehicle << " not found.\n";
        return false;
    }

    // Method to check availability
    int getAvailableSpots() const {
        return availableSpots;
    }

    // Method to list parked vehicles
    void listParkedVehicles() const {
        cout << "Parked vehicles:\n";
        for (int i = 0; i < totalSpots; ++i) {
            if (occupied[i] == 1) {
                cout << "- Spot " << i + 1 << ": " << parkedVehicles[i] << "\n";
            }
        }
    }
};

// Class history_worker
class history_worker : public worker {
public:
    void history() {
        cout << "\n\n\n\n\t\t\t\t\tHistory of Worker ";
        cout << "\t\t\t\t\t\t------------------------------\n\n";

        ifstream in("worker.txt");
        if (in.is_open()) {
            string line;
            while (getline(in, line)) {
                cout << line << endl;
            }
        } else {
            cout << "No history available.\n";
        }
    }
};



// Class List
class List {
public:
    string name;
    int id, price, profit, loss, rent;
};

// Function to display the items and billing
void display(List items[], int size, string cname, int cphone_no) {
    int total = 0;
    cout << "\n\n\n";
    cout << "\t  AAM MALL   \n";
    cout << "---------------------";
    cout << "\n";
    cout << "Name: " << cname << "\t  Phone No: " << cphone_no << "\n" << endl;

    for (int i = 0; i < size; i++) {
        cout << "ID: " << items[i].id << "\t";
        cout << "Item Name: " << items[i].name << "\t";
        cout << "Price: " << items[i].price << "\t";
        cout << "\n---------------------------------------------\n";
        total += items[i].price;
    }

    cout << "\t  Total: " << total << endl;
    cout << "\n\n\n";
    cout << "\t Thanks for visiting \n" << endl;
    cout << "\n\n\n";
}



class MallManager {
private:
    string name;  
    string contactNumber; 
    string email; 

public:
    // Constructor with parameters
    MallManager(string name, string contactNumber, string email){
    	name              =" ";
    	contactNumber     =" ";
    	email             =" ";
	}

    
    void setName( string n) {
        name = n;
    }

    void setContactNumber( string cn) {
        contactNumber = cn;
    }

    void setEmail( string e) {
        email = e;
    }

    // Getter methods
    string getName()  {
        return name;
    }

    string getContactNumber()  {
        return contactNumber;
    }

    string getEmail()  {
        return email;
    }
};
class Reviews {
private:
    string reviewerName;  
    int rating;           
    string comment;       

public:
    
    Reviews(string reviewerName = "", int rating = 0, string comment = "") {
        reviewerName = reviewerName;
        rating = rating;
        comment = comment;
    }

    
    void setReviewerName(string rn) {
        reviewerName = rn;
    }


    void setRating(int r) {
        rating = r;
    }


    void setComment(string c) {
        comment = c;
    }

    
    string getReviewerName() {
        return reviewerName;
    }

    
    int getRating()  {
        return rating;
    }


    string getComment()  {
        return comment;
    }

    
    void display() const {
        cout << "Reviewer: " << reviewerName << ", Rating: " << rating
                  << ", Comment: " << comment << endl;
    }
};
class Shop {
private:
    string name;
    string floor;
    string type; // Type of shop

public:
    void setName(string n) {
        name = n;
    }

    void setFloor(string f) {
        floor = f;
    }

    void setType(string t) {
        type = t;
    }

    string getName() {
        return name;
    }

    string getFloor() {
        return floor;
    }

    string getType() {
        return type;
    }
};

class ShoeShop {
private:
    string name;
    string floor;
    string type; // Type of shop for the second floor

public:
    void setName(string n) {
        name = n;
    }

    void setFloor(string f) {
        floor = f;
    }

    void setType(string t) {
        type = t;
    }

    string getName() {
        return name;
    }

    string getFloor() {
        return floor;
    }

    string getType() {
        return type;
    }
};

	void displayClothingChoices() {
    cout << "Choose the type of clothes:\n";
    cout << "1. Casual Clothes\n";
    cout << "2. Formal Clothes\n";
}

void displayToyChoices() {
    cout << "Choose the toy:\n";
    cout << "1. Doll\n";
    cout << "2. Action Figure\n";
    cout << "3. Puzzle\n";
    cout << "4. Toy Car\n";
    cout << "5. Teddy Bear\n";
}

void displayWatchChoices() {
    cout << "Choose the gender:\n";
    cout << "1. Male\n";
    cout << "2. Female\n";
}

void displayPerfumeChoices() {
    cout << "Choose the gender:\n";
    cout << "1. Male\n";
    cout << "2. Female\n";
}

void displayJewelryChoices() {
    cout << "Choose the type of jewelry:\n";
    cout << "1. Earrings\n";
    cout << "2. Rings\n";
    cout << "3. Necklace\n";
}

void displayCosmeticsChoices() {
    cout << "Choose the type of cosmetics:\n";
    cout << "1. Makeup Products\n";
    cout << "2. Hair Coloring Products\n";
    cout << "3. Skin Care Products\n";
}

void displayShoeChoices() {
    cout << "Choose the type of shoes:\n";
    cout << "1. Casual Shoes\n";
    cout << "2. Formal Shoes\n";
}


int main(){


    cout << "\n\n\n\t\t\t\t ---------------------------------------------";
    cout << "\n\t\t\t\t *********************************************";
    cout << "\n\t\t\t\t                                             ";
    cout << "\n\t\t\t\t                WELCOME TO                   ";
    cout << "\n\t\t\t\t                                             ";
    cout << "\n\t\t\t\t               CRYSTAL MALL                  ";
    cout << "\n\t\t\t\t                                             ";
    cout << "\n\t\t\t\t ********************************************";
    cout << "\n\t\t\t\t ---------------------------------------------";
    cout << "\n\n\n\nLoading Please Wait....";

    sleep(4);
    //system("clear"); // Use "cls" for Windows
    
    
    cout << "\n\n\n\t\t\t\t ---------------------------------------------" <<endl;
	 string uname, pwd;
    cout << "Enter username: ";
    cin >> uname;
    cout << "Enter password: ";
    cin >> pwd;

	User admin("admin", "admin123");
    if (admin.authenticate(uname, pwd)) {
        cout << "Login successful!" << endl;   
    } else {
        cout << "Login failed!" << endl;
    }

    cout << "\n\n\n\t\t\t\t ---------------------------------------------";
    cout << "\n\t\t\t\t *********************************************";
   
   

            int choice = 0;
            while (choice != 8) {
            	
             	
            	
            cout << "\n1. Worker Details\n2. Worker History\n3. Parking Management\n4. Shop Management \n5. Display and Bill Items\n6. Mall Manager Details\n7. Shop Reviews\n8. Exit\nEnter your choice: ";
            cout << "\n\n\n\t\t\t\t ---------------------------------------------";
            cout << "\n\t\t\t\t *********************************************"  <<endl;
			  
			  
		   cin >> choice;

                    switch (choice) {
                    case 1: {
                        worker w;
                        w.entery();
                        break;
                        
                      cout << "\n\n\n\t\t\t\t ---------------------------------------------";
                      cout << "\n\t\t\t\t *********************************************"  <<endl;   
                      
                    }
                    case 2: {
                        history_worker hw;
                        hw.history();
                        break;
                        
                 cout << "\n\n\n\t\t\t\t ---------------------------------------------";
                 cout << "\n\t\t\t\t *********************************************"  <<endl;    
                    }
   

		
   
    // Parking
    case 3: {
                    	 cout << "\n\n\n\t\t\t\t ---------------------------------------------";
                             cout << "\n\t\t\t\t *********************************************"  <<endl;
                        	
                        int totalSpots = 100; // Adjust the total spots as needed
                        Parking parking(totalSpots);
                        int subChoice;
                        do {
                            cout << "\n1. Park Vehicle\n2. Remove Vehicle\n3. Check Availability\n4. List Parked Vehicles\n5. Exit\nEnter your choice: ";
                            cin >> subChoice;
                            
                             cout << "\n\n\n\t\t\t\t ---------------------------------------------";
                             cout << "\n\t\t\t\t *********************************************"  <<endl;
                            switch (subChoice) {
                                case 1: {
                                    string vehicle;
                                    cout << "Enter vehicle number: ";
                                    cin >> vehicle;
                                    parking.parkVehicle(vehicle);
                                    break;
                                }
                                case 2: {
                                    string vehicle;
                                    cout << "Enter vehicle number: ";
                                    cin >> vehicle;
                                    parking.removeVehicle(vehicle);
                                    break;
                                }
                                case 3: {
                                    cout << "Available spots: " << parking.getAvailableSpots() << endl;
                                    break;
                                }
                                case 4: {
                                    parking.listParkedVehicles();
                                    break;
                                }
                                case 5: {
                                    cout << "Exiting Parking Management...\n";
                                    break;
                                }
                                default:
                                    cout << "Invalid choice! Please try again.\n";
                            }
                        } while (subChoice != 5);
                        break;
                    }


    // Display function
    //display(items, total_items, name, phone_no);

    // Clean up
  //  delete[] items;

    // Mall Manager
    
    case 4:{
		
	
    int numFloors;

    cout << "Enter the number of floors in the mall: ";
    cin >> numFloors;
	    cin.ignore();


    
   
    Shop shops[10]; // Array to store 10 shops
    for (int i = 0; i < 5; ++i) {
        shops[i].setFloor("1st Floor");
        shops[i].setType("Clothing");  
    }

    shops[0].setName("KHADI");
    shops[1].setName("AGA NOOR");
    shops[2].setName("ALKRAM");
    shops[3].setName("CROSS STICH");
    shops[4].setName("Nike");

    shops[5].setName("Toys Emporium");
    shops[5].setFloor("1st Floor");
    shops[5].setType("Toys");

    for (int i = 6; i < 10; ++i) { // Updated loop to start from index 6
        shops[i].setFloor("3rd Floor");
        shops[i].setType("Accessories");
    }

    shops[6].setName("Jewelry Palace");
    shops[7].setName("Cosmetics Haven");
    shops[8].setName("Watch House");
    shops[9].setName("Perfume Paradise");

    ShoeShop shoeShops[5]; // Array to store 5 shoe shops
    for (int i = 0; i < 5; ++i) {
        shoeShops[i].setFloor("2nd Floor");
        shoeShops[i].setType("Shoes");
    }

    shoeShops[0].setName("Adidas");
    shoeShops[1].setName("Nike");
    shoeShops[2].setName("Puma");
    shoeShops[3].setName("BORJAN");
    shoeShops[4].setName("NDURE");

    cout << "Available shops on the 1st Floor:\n";
    for (int i = 0; i < 6; ++i) {
        cout << i + 1 << ". " << shops[i].getName() << "\n";
    }

    cout << "\nAvailable shops on the 2nd Floor:\n";
    for (int i = 0; i < 5; ++i) {
        cout << i + 7 << ". " << shoeShops[i].getName() << " (Floor: " << shoeShops[i].getFloor() << ", Type: " << shoeShops[i].getType() << ")\n";
    }

    cout << "\nAvailable shops on the 3rd Floor:\n";
    for (int i = 6; i < 10; ++i) { // Updated loop to start from index 6
        cout << i + 7 << ". " << shops[i].getName() << " (Floor: " << shops[i].getFloor() << ", Type: " << shops[i].getType() << ")\n";
    }

    int shopChoice = 0;
    cout << "Enter the number of the shop you want to enter: ";
    cin >> shopChoice;
    if (shopChoice >= 1 && shopChoice <= 5) {
        int clothingChoice = 0;
        cout << "You entered " << shops[shopChoice - 1].getName() << ". Choose the type of clothes:\n";
        displayClothingChoices();
        cout << "Enter your choice: ";
        cin >> clothingChoice;

        switch (clothingChoice) {
            case 1:
                cout << "You selected Casual Clothes from " << shops[shopChoice - 1].getName() << ".\n";
                break;
            case 2:
                cout << "You selected Formal Clothes from " << shops[shopChoice - 1].getName() << ".\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } else if (shopChoice == 6) {
        int toyChoice = 0;
        cout << "You entered " << shops[shopChoice - 1].getName() << ". Choose the toy:\n";
        displayToyChoices();
        cout << "Enter your choice: ";
        cin >> toyChoice;

        switch (toyChoice) {
            case 1:
                cout << "You selected Doll from " << shops[shopChoice - 1].getName() << ".\n";
                break;
            case 2:
                cout << "You selected Action Figure from " << shops[shopChoice - 1].getName() << ".\n";
                break;
            case 3:
                cout << "You selected Puzzle from " << shops[shopChoice - 1].getName() << ".\n";
                break;
            case 4:
                cout << "You selected Toy Car from " << shops[shopChoice - 1].getName() << ".\n";
                break;
            case 5:
                cout << "You selected Teddy Bear from " << shops[shopChoice - 1].getName() << ".\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } else if (shopChoice == 12) { // Jewelry Shop
        int jewelryChoice = 0;
        cout << "You entered " << shops[shopChoice - 7].getName() << ". Choose the type of jewelry:\n";
        displayJewelryChoices();
        cout << "Enter your choice: ";
        cin >> jewelryChoice;

        switch (jewelryChoice) {
            case 1:
                cout << "You selected Earrings from " << shops[shopChoice - 7].getName() << ".\n";
                break;
            case 2:
                cout << "You selected Rings from " << shops[shopChoice - 7].getName() << ".\n";
                break;
            case 3:
                cout << "You selected Necklace from " << shops[shopChoice - 7].getName() << ".\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } else if (shopChoice == 13) { // Cosmetics Shop
        int cosmeticChoice = 0;
        cout << "You entered " << shops[shopChoice - 7].getName() << ". Choose the type of cosmetics:\n";
        displayCosmeticsChoices();
        cout << "Enter your choice: ";
        cin >> cosmeticChoice;

        switch (cosmeticChoice) {
            case 1:
                cout << "You selected Makeup Products from " << shops[shopChoice - 7].getName() << ".\n";
                break;
            case 2:
                cout << "You selected Hair Coloring Products from " << shops[shopChoice - 7].getName() << ".\n";
                break;
            case 3:
                cout << "You selected Skin Care Products from " << shops[shopChoice - 7].getName() << ".\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } else if (shopChoice == 14) { // Watch Shop
        int watchChoice = 0;
        cout << "You entered " << shops[shopChoice - 7].getName() << ". Choose the gender:\n";
        displayWatchChoices();
        cout << "Enter your choice: ";
        cin >> watchChoice;

        switch (watchChoice) {
            case 1:
                cout << "You selected Male Watches from " << shops[shopChoice - 7].getName() << ".\n";
                break;
            case 2:
                cout << "You selected Female Watches from " << shops[shopChoice - 7].getName() << ".\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } else if (shopChoice == 15) { // Perfume Shop
        int perfumeChoice = 0;
        cout << "You entered " << shops[shopChoice - 7].getName() << ". Choose the gender:\n";
        displayPerfumeChoices();
        cout << "Enter your choice: ";
        cin >> perfumeChoice;

        switch (perfumeChoice) {
            case 1:
                cout << "You selected Male Perfumes from " << shops[shopChoice - 7].getName() << ".\n";
                break;
            case 2:
                cout << "You selected Female Perfumes from " << shops[shopChoice - 7].getName() << ".\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } else if (shopChoice >= 7 && shopChoice <= 11) {
        int shoeChoice = 0;
        cout << "You entered " << shoeShops[shopChoice - 7].getName() << ". Choose the type of shoes:\n";
        displayShoeChoices();
        cout << "Enter your choice: ";
        cin >> shoeChoice;

        switch (shoeChoice) {
            case 1:
                cout << "You selected Casual Shoes from " << shoeShops[shopChoice - 7].getName() << ".\n";
                break;
            case 2:
                cout << "You selected Formal Shoes from " << shoeShops[shopChoice - 7].getName() << ".\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } else {
        cout << "Invalid shop choice.\n";
    }
        break;   
}    




       case 5 : {
    const int MAX_ITEMS = 100; // Adjust the maximum number of items as needed
    List items[MAX_ITEMS];
    int total_items = 0;

    cout << "Enter customer name: ";
    string name;
    cin >> name;

    cout << "Enter customer phone number: ";
    int phone_no;
    cin >> phone_no;

    cout << "Enter total items: ";
    cin >> total_items;

    if (total_items > MAX_ITEMS) {
        cout << "Error: Too many items. The maximum is " << MAX_ITEMS << ".\n";
        return 1;
    }

    // Insert items
    for (int i = 0; i < total_items; i++) {
        items[i].id = (i + 1);
        cout << "Enter item " << (i + 1) << " name: ";
        cin >> items[i].name;
        cout << "Enter price: ";
        cin >> items[i].price;
    }

    int customerChoice;
    cout << "\nCustomer Choice:\n";
    cout << "1. Display and Bill Items\n";
    cout << "2. Exit\n";
    cout << "Enter your choice: ";
    cin >> customerChoice;

    switch (customerChoice) {
        case 1: {
            display(items, total_items, name, phone_no);
            break;
        }
        case 2: {
            cout << "Exiting customer menu...\n";
            break;
        }
        default:
            cout << "Invalid choice! Please try again.\n";
    }
break;
}




case 6 : {
	
	int numFloors;

    cout << "Enter the number of floors in the mall: ";
    cin >> numFloors;
	    cin.ignore();


   string floorManagerDetails[numFloors];

    
	  for (int i = 0; i < numFloors; ++i) {
      string name, contactNumber, email;

       cout << "\nFloor " << i + 1 << " Manager Details" << std::endl;
       cout << "Name: ";
       cin>>name;

       cout << "Contact Number: ";
       cin>>contactNumber;

       cout << "Email: ";
       cin>> email;

        
        floorManagerDetails[i] = "Name: " + name + ", Contact Number: " + contactNumber + ", Email: " + email;
    }

    
    cout << "\nManager Details for Each Floor:" << endl;
    for (int i = 0; i < numFloors; ++i) {
     cout << "\nFloor " << i + 1 << ":" << endl;
    cout << floorManagerDetails[i] << endl;
    }
	break;
}
    
    
     case 7: {
                    	
                    	 cout << "\n\n\n\t\t\t\t ---------------------------------------------";
                         cout << "\n\t\t\t\t *********************************************"  <<endl;
                        Reviews review;
                        string reviewerName;
                        int rating;
                        string comment;

                        cout << "Enter Reviewer Name: ";
                        cin >> reviewerName;
                        review.setReviewerName(reviewerName
);

                        cout << "Enter Rating (1-5): ";
                        cin >> rating;
                        review.setRating(rating);

                        cout << "Enter Comment: ";
                        cin.ignore(); // Clear the input buffer
                        getline(cin, comment);
                        review.setComment(comment);

                        cout << "\nReview Details:\n";
                        review.display();
                        break;
                    }
            
			 case 8:
                        cout << "Exiting program...\n";
                        break;
                    default:
                        cout << "Invalid choice! Please try again.\n";
                }
			
			        
}
    
    
}
