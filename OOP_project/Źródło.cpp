#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/statement.h> 
#include <iostream> 
#include <iomanip>
#include <mysql_connection.h> 
#include <mysql_driver.h> 

using namespace std;
int main()
{
	try {
		sql::mysql::MySQL_Driver* driver;
		sql::Connection* con;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("tcp://localhost:3306",
			"root", "Krzysiu13");

		con->setSchema("library"); // your database name 

		sql::Statement* stmt;
		stmt = con->createStatement();

		// SQL query to create a table 
		string createTableSQL
			= "CREATE TABLE IF NOT EXISTS GFGCourses ("
			"id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,"
			"courses VARCHAR(255) NOT NULL"
			")";

		stmt->execute(createTableSQL);
		stmt->execute("TRUNCATE TABLE GFGCourses");
		string insertDataSQL
			= "INSERT INTO GFGCourses (courses) VALUES "
			"('DSA'),('C++'),('JAVA'),('PYTHON')";

		stmt->execute(insertDataSQL);

		// SQL query to retrieve data from the table 
		string selectDataSQL = "SELECT * FROM GFGCourses";

		sql::ResultSet* res
			= stmt->executeQuery(selectDataSQL);

		cout << "GFGCourses Table:" << endl;
		cout << left << setw(5) << "ID" << setw(20) << "Course" << endl;
		cout << string(25, '-') << endl;
		string firstCourse = " ";
		// Loop through the result set and display data 
		int count = 0;
		while (res->next()) {
			if (res->getString("courses") == firstCourse) {
				break;
			}
			firstCourse = res->getString("courses");
			cout << left << setw(5) << res->getInt("id")
				<< setw(20) << res->getString("courses") << endl;
		}

		delete res;

		selectDataSQL = "SELECT * FROM books";
		sql::ResultSet* res1 = stmt->executeQuery(selectDataSQL);

		cout << "\nBooks Table:" << endl;
		cout << left << setw(5) << "ID" << setw(30) << "Title"
			<< setw(25) << "Author" << endl;
		cout << string(60, '-') << endl;

		while (res1->next()){
			cout << left << setw(5) << res1->getInt("id")
				<< setw(30) << res1->getString("title")
				<< setw(25) << res1->getString("author") << endl;
		}
		delete res1;
		delete stmt;
		delete con;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
		cerr << "SQL State: " << e.getSQLState() << endl;
		cerr << "Error Code: " << e.getErrorCode() << endl;
	}

	return 0;
}
