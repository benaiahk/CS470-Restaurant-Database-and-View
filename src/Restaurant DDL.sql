create schema restaurantdb; 

use restaurantdb; 

##
## TABLE CREATION
##
CREATE TABLE restaurant (
	restaurantID INT NOT NULL,
    restaurantName VARCHAR(100) NOT NULL,
    restaurantLoc VARCHAR(100) NOT NULL
);

CREATE TABLE position (
	positionID INT NOT NULL,
    positionTitle VARCHAR(100) NOT NULL,
    positionPay DECIMAL NOT NULL
		CHECK (positionPay >= 0)
);

CREATE TABLE employee (
	employeeID INT NOT NULL,
    employeeName VARCHAR(100) NOT NULL,
    employeeAddress VARCHAR(100) NOT NULL,
    employeePosition INT NOT NULL
);

CREATE TABLE menu_items (
	itemName VARCHAR(100) NOT NULL,
    itemPrice DECIMAL NOT NULL
		CHECK (itemPrice >= 0),
    itemType VARCHAR(5) NOT NULL
		CHECK (itemType = 'Food' OR itemType = 'Drink')
);

CREATE TABLE restaurant_menu (
	restaurantID INT NOT NULL,
    itemName VARCHAR(100) NOT NULL,
    itemCount INT NOT NULL DEFAULT 0,
    itemStatus VARCHAR(8) DEFAULT NULL
);

CREATE TABLE employee_restaurant (
	employeeID INT NOT NULL,
    employeeRestaurant INT NOT NULL
);

##
## TRIGGER CREATION
##
DELIMITER //
    CREATE TRIGGER updStatus BEFORE INSERT 
        ON restaurant_menu
        FOR EACH ROW
        BEGIN
            IF NEW.itemCount = 0 THEN
                SET NEW.itemStatus = 'no_stock';
            ELSEIF NEW.itemCount < 30 THEN
                SET NEW.itemStatus = 'lo_stock';
            ELSEIF NEW.itemcount>=30 THEN
				SET NEW.itemStatus = 'in_stock'; 
            END IF;
        END;//
DELIMITER ;

##
## ENTRY CREATION
##

# resaurant
INSERT INTO restaurant (restaurantID, restaurantName, restaurantLoc) 
	VALUES (100, "Taco Bell", "Kansas City"), (101, "Wendys", "Kansas City"), 
		   (102, "McDonalds", "St Louis"), (103, "Chick fil A", "St Louis");

# position
INSERT INTO position (positionID, positionTitle, positionPay) 
	VALUES (1, "Manager", 20.0), (2, "Cashier", 9.50), (3, "Cook", 10.0), (4, "Dishwasher", 9.50);

# employee
INSERT INTO employee (employeeID, employeeName, employeeAddress, employeePosition) 
	VALUES (1000,"Tom Jones", "123 Cherry Street", 1), (1001,"Arnold Palmer", "12 Berry Street", 2), (1002, "Susan Caroline", "21 Jump Street", 4),
		   (1003, "Joe Johnson", "34 Oak Avenue", 2), (1004, "Alex Darby", "14 Apple Lane", 3), (1005, "Antonio Banderras", "24 Clover Street", 4), 
		   (1006, "Dillon Cole", "28 Mandella Lane", 1), (1007, "Bob Dylan", "1433 Bridgeton Street", 2), (1008, "Stacy Jackson", "12 Oak Parkway", 3),
		   (1009, "Albert Jones", "67 Orange Lane", 2), (1010, "Jeff Filmer", "10 Palm Spring Street", 2), (1011, "Rob Lowe", "6 Battery Street", 3),
		   (1012, "Jessie Johnson", "123 Apple Street", 4), (1013, "Ari Cole", "1772 Chesterfield Parkway", 1), (1014, "Harry Potter", "Hogwarts", 4),
		   (1015, "Chester Joseph", "24 Brown Road", 3), (1016, "John Jacobs", "12 Lemon Lane", 2), (1017, "Devin Stephenson", "23 Charlie Road", 2),
		   (1018, "Ian Domingo", "5532 Appleton Avenue", 4), (1019, "Ron Derrick", "1233 Alley Road", 2), (1020, "Tony Appollo", "54 Chester Street", 3),
		   (1021, "Bill Gates", "76 Old Town Street", 3), (1022, "Timmy Thompson", "34 Tree Road", 2);
INSERT INTO employee (employeeID, employeeName, employeeAddress, employeePosition)
	VALUES (1023, "Harrison Barnes", "11 Water Lane", 2), (1024, "Bridgit Brookes", "22 Park Road", 2), (1025, "John Stokes", "14 Ark Street", 4),
		   (1026, "Lydia Carson", "55 Downtown Street", 3), (1027, "Landon Jacobs", "68 Wood Road", 3), (1028, "Charlie Puth", "88 Baseball Street", 3),
		   (1029, "Carlie Jones", "1435 Cherry Street", 1), (1030, "Peter Bonello", "1745 Briarwood Lane", 1), (1031, "Patrick Davidson", "123 Color Road", 2),
		   (1032, "Derrick Appleton", "1543 Breeze Way", 3), (1033, "Donovan Jones", "43 Chester Street", 1), (1034, "Bailey Gordon", "2343 Oakley Road", 2),
		   (1035, "Lamont Jackson", "65 Fortitude Avenue", 3), (1036, "Brad Paisley", "12 Dynamite Road", 3), (1037, "Tyler Carlson", "123 Dragon Street", 4),
		   (1038, "Peggy Thompson", "15 Parkway Street", 2), (1039, "Billy Stevenson", "34 Love Street", 4), (1040, "Mike Brown", "65 Cherry Street", 3),
		   (1041, "Shawn Spiel", "77 Bowling Street", 3), (1042, "Leah Tony", "23 Oakley Avenue", 2), (1043, "Allie Brooklyn", "54 America Blvd", 3);
INSERT INTO employee (employeeID, employeeName, employeeAddress, employeePosition)
	VALUES (1044, "LeShawnda Brown", "1433 Street Street", 3), (1045, "Bob James", "1722 Orangutan Alley", 2), (1046, "Steve Bo", "5688 Box Lane", 4),
		   (1047, "Abby Appleton", "65 Brooke Alley", 2), (1048, "Tommy Lee", "4346 Rockhill Street", 1), (1049, "Bill Preston", "7899 Oaktown Parkway", 2),
		   (1050, "Timothy Brackton", "32 Apple Street", 1), (1051, "Charlene Meyers", "7888 Bridge Street", 2), (1052, "Noah Vanderbolt", "278 West Drive", 3),
		   (1053, "Alvin Timothy", "1508 Marion Drive", 4), (1054, "Oakley Jones", "1187 Augusta Park", 3), (1055, "Thomas Packer", "2353 Stonecoal Road", 2),
		   (1056, "Macey Peterson", "3244 Crestview Manor", 1), (1057, "Tammy Lo", "2431 Elk Creek Road", 2), (1058, "Tony Gonzolas", "234 Orphan Road", 4),
		   (1059, "Chester Sea", "2423 Langtown Road", 2), (1060, "Bob Barker", "881 Point Street", 1), (1061, "Jim Thompson", "3423 Ben Street", 1),
		   (1062, "Sally Brookes", "6232 Stoney Road", 4), (1063, "Chrystal Beth", "3452 Fairfield Road", 2), (1064, "Sharon Baker", "4877 John Avenue", 2),
		   (1065, "Jeremy Johnson", "3424 Eagle Drive", 3), (1066, "Theresa Enzyme", "24 Rogers Street", 3), (1067, "Hermoine Granger", "2343 Reynolds Drive", 4),
		   (1068, "Emelia Parker", "34 Felosa Lane", 3);
INSERT INTO employee (employeeID, employeeName, employeeAddress, employeePosition) 
	VALUES (1069, "Jordan Jones", "2342 Foley Drive", 2), (1070, "Michael Dubai", "3453 Pacific Avenue", 3), (1071, "Carl Junior", "1232 Golden Street", 1),
		   (1072, "Dominic Dee", "1876 Tully Street", 4), (1073, "Norman Reeds", "3433 Walkers Ridge Way", 2), (1074, "Luther Preston", "3422 Horseshoe Lane", 4),
		   (1075, "Nathan Fielder", "3242 Jarvis Street", 3), (1076, "Alvin Kamara", "2342 Tetrik Road", 3), (1077, "Chelsea Stroben" , "1344 Butternut Lane", 1),
		   (1078, "Jenna Baker", "33 Irish Lane", 2), (1079, "Peter Parker", "2333 Hillcrest Lane", 2), (1080, "Derrick Arkleson", "2657 Sundown Lane", 4),
		   (1081, "Fendrick Lamar", "2223 Arlington Avenue", 3), (1082, "Milly Monroe", "8643 Hannah Street", 2), (1083, "Malcome Brogdon", "4511 Linda Street", 2),
		   (1084, "Joseph Jeans", "2344 Stutler Lane", 4), (1085, "Randy Jackson", "3270 Bottom Lane", 3), (1086, "Lindsey Pates", "5444 Spring Lane", 2),
		   (1087, "Mark Antonio", "4774 Mesa Drive", 3), (1088, "Allie Deal", "9877 East Avenue", 2), (1089, "Tim Ansel", "4322 Goodwin Avenue", 2),
		   (1090, "John Johnson", "2024 Stratford Drive", 4), (1091, "Devin Domino", "2332 Cambridge Drive", 3);
    
# menu_items
INSERT INTO menu_items (itemName, itemPrice, itemType) 
	VALUES ("Crunchy Taco", 1.29, "Food"), ("Soft Taco", 1.29, "Food"), ("Cheesy Gordita Crunch", 3.59, "Food"),
		   ("Doritos Locos Taco", 1.89, "Food"), ("Soft Taco Supreme", 1.79, "Food"), ("Crunchy Taco Supreme", 1.79, "Food"),
		   ("Spicy Potato Soft Taco", 1.00, "Food"), ("Bean Burrito", 1.29, "Food"), ("Beefy Fritos Burrito", 1.00, "Food"),
		   ("Beefy Five Layer Burrito", 2.39, "Food"), ("Quesarito", 3.19, "Food"), ("Burrito Supreme", 3.49, "Food"),
		   ("Seven Layer Burrito", 3.29, "Food"), ("Beefy Nacho Griller", 1.99, "Food"), ("Crunchwrap Supreme", 3.69, "Food"),
		   ("Nachos Bellgrande", 3.69, "Food"), ("Chicken Quesadilla", 3.79, "Food"), ("Baja Blast Freeze", 2.69, "Drink"),
		   ("Fountain Drink", 1.99, "Drink");
INSERT INTO menu_items (itemName, itemPrice, itemType)
	VALUES ("Daves Single with Cheese", 4.19, "Food"), ("Daves Double with Cheese", 5.19, "Food"), 
		   ("Daves Triple with Cheese", 6.09, "Food"), ("Baconator", 6.09, "Food"), ("Son of Baconator", 4.69, "Food"),
		   ("Spicy Chicken", 4.69, "Food"), ("Homestyle Chicken", 4.69, "Food"), ("Ten Piece Nuggets", 5.99, "Food"),
		   ("Jr Cheeseburger Deluxe", 1.89, "Food"), ("Chili", 2.09, "Food"), ("Small Fries", 1.69, "Food"),
		   ("Medium Fries", 1.99, "Food"), ("Large Fries", 2.19, "Food"), ("Cheese Fries", 2.19, "Food"),
		   ("Caeser Side Salad", 1.49, "Food"), ("4 for 4 combo", 4.00, "Food"), ("Hot Coffee", 0.99, "Drink"), 
		   ("Frosty", 1.99, "Drink");
INSERT INTO menu_items (itemName, itemPrice, itemType)
	VALUES ("Big Mac", 3.99, "Food"), ("McDouble", 1.39, "Food"), ("Quarter Pounder with Cheese", 3.79, "Food"),
		   ("Bacon Clubhouse Burger", 4.49, "Food"), ("McChicken", 1.29, "Food"), ("Chicken Wrap", 4.39, "Food"),
		   ("Filet O Fish", 3.79, "Food"), ("10 Piece Nuggets", 4.49, "Food"), ("Southwest Salad", 4.79, "Food"),
		   ("Double Cheeseburger", 1.69, "Food"), ("3 Cookies", 1.00, "Food"), ("Cone", 1.00, "Food"),
		   ("Smoothie", 1.89, "Drink"), ("Frappe", 2.89, "Drink"), ("Espresso", 2.89, "Drink"),
		   ("Soft Drink", 1.29, "Drink");
INSERT INTO menu_items (itemName, itemPrice, itemType)
	VALUES ("Chicken Sandwich", 3.75, "Food"), ("Deluxe Sandwich", 4.45, "Food"), ("Spicy Chicken Sandwich", 3.99, "Food"),
		   ("Spicy Deluxe Sandwich", 4.69, "Food"), ("Grilled Chicken Sandwich", 5.15, "Food"), ("Grilled Chicken Club", 6.55, "Food"),
		   ("Chicken Nuggets", 3.85, "Food"), ("Chicken Strips", 4.19, "Food"), ("Grilled Chicken Wrap", 6.29, "Food"),
		   ("Grilled Nuggets", 4.59, "Food"), ("Cobb Salad", 7.99, "Food"), ("Spicy Southwest Salad", 8.19, "Food"),
		   ("Waffle Fries", 1.95, "Food"), ("Fruit Cup", 3.15, "Food"), ("Mac and Cheese", 3.15, "Food"),
		   ("Milkshake", 3.25, "Drink"), ("Frosted Coffee", 3.25, "Drink"), ("Chocolate Chip Cookie", 1.29, "Food");

# restaurant_menu
INSERT INTO restaurant_menu (restaurantID, itemName, itemCount, itemStatus) 
	VALUES (100, "Crunchy Taco", 100, "in_stock"), (100, "Soft Taco", 95, "in_stock"), (100, "Cheesy Gordita Crunch", 40, "in_stock"),
		   (100, "Doritos Locos Taco", 28, "lo_stock"), (100, "Soft Taco Supreme", 80, "in_stock"), (100, "Crunchy Taco Supreme", 85, "in_stock"),
		   (100, "Spicy Potato Soft Taco", 55, "in_stock"), (100, "Bean Burrito", 100, "in_stock"), (100, "Beefy Fritos Burrito", 90, "in_stock"),
		   (100, "Beefy Five Layer Burrito", 75, "in_stock"), (100, "Quesarito", 80, "in_stock"), (100, "Burrito Supreme", 60, "in_stock"),
		   (100, "Seven Layer Burrito", 28, "lo_stock"), (100, "Beefy Nacho Griller", 50, "in_stock"), (100, "Crunchwrap Supreme", 55, "in_stock"),
		   (100, "Nachos Bellgrande", 0, "no_stock"), (100, "Chicken Quesadilla", 66, "in_stock"), (100, "Baja Blast Freeze", 40, "in_stock"),
		   (100, "Fountain Drink", 100, "in_stock");
INSERT INTO restaurant_menu (restaurantID, itemName, itemCount, itemStatus) 
	VALUES (101, "Daves Single with Cheese", 100, "in_stock"), (101, "Daves Double with Cheese", 80, "in_stock"), 
		   (101, "Daves Triple with Cheese", 70, "in_stock"), (101, "Baconator", 73, "in_stock"), (101, "Son of Baconator", 50, "in_stock"),
		   (101, "Spicy Chicken", 80, "in_stock"), (101, "Homestyle Chicken", 34, "in_stock"), (101, "Ten Piece Nuggets", 100, "in_stock"),
		   (101, "Jr Cheeseburger Deluxe", 65, "in_stock"), (101, "Chili", 40, "in_stock"), (101, "Small Fries", 120, "in_stock"),
		   (101, "Medium Fries", 100, "in_stock"), (101, "Large Fries", 80, "in_stock"), (101, "Cheese Fries", 60, "in_stock"),
		   (101, "Caeser Side Salad", 23, "lo_stock"), (101, "4 for 4 combo", 67, "in_stock"), (101, "Hot Coffee", 35, "in_stock"), 
		   (101, "Frosty", 60, "in_stock");
INSERT INTO restaurant_menu (restaurantID, itemName, itemCount, itemStatus)
	VALUES (102, "Big Mac", 90, "in_stock"), (102, "McDouble", 90, "in_stock"), (102, "Quarter Pounder with Cheese", 50, "in_stock"),
		   (102, "Bacon Clubhouse Burger", 40, "in_stock"), (102, "McChicken", 80, "in_stock"), (102, "Chicken Wrap", 20, "lo_stock"),
		   (102, "Filet O Fish", 50, "in_stock"), (102, "10 Piece Nuggets", 60, "in_stock"), (102, "Southwest Salad", 40, "in_stock"),
		   (102, "Small Fries", 120, "in_stock"), (102, "Medium Fries", 100, "in_stock"), (102, "Large Fries", 80, "in_stock"),
		   (102, "Double Cheeseburger", 40, "in_stock"), (102, "3 Cookies", 15, "lo_stock"), (102, "Cone", 0, "no_stock"),
		   (102, "Smoothie", 40, "in_stock"), (102, "Frappe", 30, "in_stock"), (102, "Espresso", 40, "in_stock"),
		   (102, "Soft Drink", 80, "in_stock");
INSERT INTO restaurant_menu (restaurantID, itemName, itemCount, itemStatus)
	VALUES (103, "Chicken Sandwich", 120, "in_stock"), (103, "Deluxe Sandwich", 100, "in_stock"), (103, "Spicy Chicken Sandwich", 80, "in_stock"),
		   (103, "Spicy Deluxe Sandwich", 50, "in_stock"), (103, "Grilled Chicken Sandwich", 80, "in_stock"), (103, "Grilled Chicken Club", 70, "in_stock"),
		   (103, "Chicken Nuggets", 67, "in_stock"), (103, "Chicken Strips", 45, "in_stock"), (103, "Grilled Chicken Wrap", 31, "in_stock"),
		   (103, "Grilled Nuggets", 50, "in_stock"), (103, "Cobb Salad", 40, "in_stock"), (103, "Spicy Southwest Salad", 15, "lo_stock"),
		   (103, "Waffle Fries", 100, "in_stock"), (103, "Fruit Cup", 49, "in_stock"), (103, "Mac and Cheese", 60, "in_stock"),
		   (103, "Milkshake", 60, "in_stock"), (103, "Frosted Coffee", 38, "in_stock"), (103, "Chocolate Chip Cookie", 40, "in_stock");
    
# employee_restaurant
INSERT INTO employee_restaurant (employeeID, employeeRestaurant) 
	VALUES (1000, 100), (1001, 100), (1002, 100), (1003, 100), (1004, 100), (1005, 100), 
		   (1006, 100), (1007, 100), (1008, 100), (1009, 100), (1010, 100), (1011, 100),
		   (1012, 100), (1013, 100), (1014, 100), (1015, 100), (1016, 100), (1017, 100),
		   (1018, 100), (1019, 100), (1020, 100), (1021, 100), (1022, 100);
INSERT INTO employee_restaurant (employeeID, employeeRestaurant)
	VALUES (1023, 101), (1024, 101), (1025, 101), (1026, 101), (1027, 101), (1028, 101),
		   (1029, 101), (1030, 101), (1031, 101), (1032, 101), (1033, 101), (1034, 101),
		   (1035, 101), (1036, 101), (1037, 101), (1038, 101), (1039, 101), (1040, 101),
		   (1041, 101), (1042, 101), (1043, 101);
INSERT INTO employee_restaurant (employeeID, employeeRestaurant)
	VALUES (1044, 102), (1045, 102), (1046, 102), (1047, 102), (1048, 102), (1049, 102),
		   (1050, 102), (1051, 102), (1052, 102), (1053, 102), (1054, 102), (1055, 102),
		   (1056, 102), (1057, 102), (1058, 102), (1059, 102), (1060, 102), (1061, 102),
		   (1062, 102), (1063, 102), (1064, 102), (1065, 102), (1066, 102), (1067, 102),
		   (1068, 102);
INSERT INTO employee_restaurant (employeeID, employeeRestaurant) 
	VALUES (1069, 103), (1070, 103), (1071, 103), (1072, 103), (1073, 103), (1074, 103),
		   (1075, 103), (1076, 103), (1077, 103), (1078, 103), (1079, 103), (1080, 103),
           (1081, 103), (1082, 103), (1083, 103), (1084, 103), (1085, 103), (1086, 103),
           (1087, 103), (1088, 103), (1089, 103), (1090, 103), (1091, 103);

##
## CONSTRAINT CREATION
##
ALTER TABLE restaurant
	ADD CONSTRAINT PRIMARY KEY (restaurantID);

ALTER TABLE position
	ADD CONSTRAINT PRIMARY KEY (positionID, positionTitle);
	
ALTER TABLE employee
	ADD CONSTRAINT PRIMARY KEY (employeeID),
	ADD CONSTRAINT FOREIGN KEY (employeePosition)
		REFERENCES position (positionID);
		
ALTER TABLE menu_items
	ADD CONSTRAINT PRIMARY KEY (itemName);
	
ALTER TABLE restaurant_menu
	ADD CONSTRAINT PRIMARY KEY (restaurantID, itemName),
    ADD CONSTRAINT FOREIGN KEY (itemName)
		REFERENCES menu_items(itemName),
	ADD CONSTRAINT FOREIGN KEY (restaurantID)
		REFERENCES restaurant(restaurantID);
		
ALTER TABLE employee_restaurant
	ADD CONSTRAINT 	PRIMARY KEY (employeeID, employeeRestaurant), 
	ADD CONSTRAINT FOREIGN KEY (employeeID)
		REFERENCES employee (employeeID), 
	ADD CONSTRAINT FOREIGN KEY (employeeRestaurant) 
		REFERENCES restaurant(restaurantID);

##
## PROCEDURE CREATION
##
DELIMITER //
CREATE PROCEDURE ShowAllRestaurant()
BEGIN
	SELECT r.restaurantID, restaurantName, restaurantLoc, COUNT(e.employeeID) as numEmployees
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
        GROUP BY r.restaurantID 
		ORDER BY r.restaurantID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRestaurant
(IN rid int, IN rname varchar(100), IN rlocat varchar(100), IN rcount int)
BEGIN
	SELECT r.restaurantID, restaurantName, restaurantLoc, COUNT(e.employeeID) as numEmployees
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
		WHERE rid = r.restaurantID AND rname = restaurantName AND rlocat = restaurantLoc
        GROUP BY r.restaurantID 
			HAVING COUNT(e.employeeID) = rcount
		ORDER BY r.restaurantID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRestaurantID
(IN rid int)
BEGIN
	SELECT r.restaurantID, restaurantName, restaurantLoc, COUNT(e.employeeID) as numEmployees
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
		WHERE rid = r.restaurantID
        GROUP BY r.restaurantID
        ORDER BY r.restaurantID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRestaurantName
(IN rname varchar(100))
BEGIN
	SELECT r.restaurantID, restaurantName, restaurantLoc, COUNT(e.employeeID) as numEmployees
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
		WHERE rname = restaurantName
        GROUP BY r.restaurantID
		ORDER BY r.restaurantID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRestaurantLoc
(IN rloc varchar(100))
BEGIN
	SELECT r.restaurantID, restaurantName, restaurantLoc, COUNT(e.employeeID) as numEmployees
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
		WHERE rloc = restaurantLoc
        GROUP BY r.restaurantID
		ORDER BY r.restaurantID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRestaurantCnt
(IN rcount int)
BEGIN
	SELECT r.restaurantID, restaurantName, restaurantLoc, COUNT(e.employeeID) as numEmployees
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
        GROUP BY r.restaurantID 
			HAVING COUNT(e.employeeID) = rcount
		ORDER BY r.restaurantID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchEmployeeID
(IN eid int)
BEGIN
	SELECT * FROM employee
		INNER JOIN position ON employeePosition = positionID
		WHERE employeeID = eid
        ORDER BY employeeID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchEmployeeName
(IN ename varchar(100))
BEGIN
	SELECT * FROM employee
		INNER JOIN position ON employeePosition = positionID
		WHERE employeeName = ename
        ORDER BY employeeID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchEmployeeAddr
(IN eaddr varchar(100))
BEGIN
	SELECT * FROM employee
		INNER JOIN position ON employeePosition = positionID
		WHERE employeeAddress = eaddr
        ORDER BY employeeID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchEmployee
(IN eid int, IN ename varchar(100), IN eaddr varchar(100))
BEGIN
	SELECT * FROM employee
		INNER JOIN position ON employeePosition = positionID
		WHERE employeeName = ename AND employeeID = eid AND employeeAddress = eaddr
        ORDER BY employeeID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchPositionPay
(IN ppay decimal)
BEGIN
	SELECT * FROM employee
		INNER JOIN position ON employeePosition = positionID
		WHERE positionPay = ppay
        ORDER BY employeeID, positionID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchPositionID
(IN pid int)
BEGIN
	SELECT * FROM employee
		INNER JOIN position ON employeePosition = positionID
		WHERE positionID = pid
        ORDER BY employeeID, positionID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchPositionTitle
(IN ptitle varchar(100))
BEGIN
	SELECT * FROM employee
		INNER JOIN position ON employeePosition = positionID
		WHERE positionTitle = ptitle
        ORDER BY employeeID, positionID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchPosition
(IN ptitle varchar(100), IN pid int, IN ppay decimal)
BEGIN
	SELECT * FROM employee
		INNER JOIN position ON employeePosition = positionID
		WHERE positionTitle = ptitle AND positionID = pid AND positionPay = ppay
        ORDER BY employeeID, positionID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRestaurantEmp
(IN rid int, IN rname varchar(100), IN rlocat varchar(100), IN eid int, IN ename varchar(100), IN eaddr varchar(100))
BEGIN
	SELECT r.restaurantID, r.restaurantName, r.restaurantLoc, e.employeeID, e.employeeName, e.employeeAddress 
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
		WHERE restaurantID = rid AND restaurantName = rname AND restaurantLoc = rlocat AND eid = e.employeeID AND ename = employeeName AND eaddr = employeeAddress
		ORDER BY r.restaurantID, e.employeeID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE ShowAllRestaurantEmp()
BEGIN
	SELECT r.restaurantID, r.restaurantName, r.restaurantLoc, e.employeeID, e.employeeName, e.employeeAddress 
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
		ORDER BY r.restaurantID, e.employeeID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRestaurantIDEmp
(IN rid int)
BEGIN
	SELECT r.restaurantID, r.restaurantName, r.restaurantLoc, e.employeeID, e.employeeName, e.employeeAddress 
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
		WHERE restaurantID = rid
		ORDER BY r.restaurantID, e.employeeID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRestaurantNameEmp
(IN rname varchar(100))
BEGIN
	SELECT r.restaurantID, r.restaurantName, r.restaurantLoc, e.employeeID, e.employeeName, e.employeeAddress 
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
		WHERE restaurantName = rname
		ORDER BY r.restaurantID, e.employeeID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRestaurantLocEmp
(IN rloc varchar(100))
BEGIN
	SELECT r.restaurantID, r.restaurantName, r.restaurantLoc, e.employeeID, e.employeeName, e.employeeAddress 
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
		WHERE restaurantLoc = rloc
		ORDER BY r.restaurantID, e.employeeID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRestaurantEmpID
(IN erid int)
BEGIN
	SELECT r.restaurantID, r.restaurantName, r.restaurantLoc, e.employeeID, e.employeeName, e.employeeAddress 
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
		WHERE erid = e.employeeID
		ORDER BY r.restaurantID, e.employeeID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRestaurantEmpName
(IN ername varchar(100))
BEGIN
	SELECT r.restaurantID, r.restaurantName, r.restaurantLoc, e.employeeID, e.employeeName, e.employeeAddress 
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
		WHERE ername = employeeName
		ORDER BY r.restaurantID, e.employeeID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRestaurantEmpAddr
(IN eraddr varchar(100))
BEGIN
	SELECT r.restaurantID, r.restaurantName, r.restaurantLoc, e.employeeID, e.employeeName, e.employeeAddress 
		FROM restaurant AS r
			INNER JOIN employee_restaurant AS er ON r.restaurantID = er.employeeRestaurant
			INNER JOIN employee AS e ON er.employeeID = e.employeeID
		WHERE eraddr = employeeAddress
		ORDER BY r.restaurantID, e.employeeID;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE ShowAllRM()
BEGIN
	SELECT r.restaurantID, restaurantName, rm.itemName, itemPrice, itemType, itemCount, itemStatus
		FROM restaurant AS r 
        INNER JOIN restaurant_menu AS rm ON r.restaurantID = rm.restaurantID
        INNER JOIN menu_items AS mi ON rm.itemName = mi.itemName
        ORDER BY r.restaurantID, itemStatus;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRM
(IN rid int, IN rname varchar(100), IN iname varchar(100), IN icount int, IN istock varchar(100), IN itype varchar(100))
BEGIN
	SELECT r.restaurantID, restaurantName, rm.itemName, itemPrice, itemType, itemCount, itemStatus
		FROM restaurant AS r 
        INNER JOIN restaurant_menu AS rm ON r.restaurantID = rm.restaurantID
        INNER JOIN menu_items AS mi ON rm.itemName = mi.itemName
        WHERE rid = r.restaurantID AND rname = restaurantName AND iname = rm.itemName AND icount = itemCount AND istock = itemStatus AND itype = itemType
        ORDER BY r.restaurantID, itemStatus;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRMID
(IN rid int)
BEGIN
	SELECT r.restaurantID, restaurantName, rm.itemName, itemPrice, itemType, itemCount, itemStatus
		FROM restaurant AS r 
        INNER JOIN restaurant_menu AS rm ON r.restaurantID = rm.restaurantID
        INNER JOIN menu_items AS mi ON rm.itemName = mi.itemName
        WHERE rid = r.restaurantID
        ORDER BY r.restaurantID, itemStatus;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRMName
(IN rname varchar(100))
BEGIN
	SELECT r.restaurantID, restaurantName, rm.itemName, itemPrice, itemType, itemCount, itemStatus
		FROM restaurant AS r 
        INNER JOIN restaurant_menu AS rm ON r.restaurantID = rm.restaurantID
        INNER JOIN menu_items AS mi ON rm.itemName = mi.itemName
        WHERE rname = restaurantName
        ORDER BY r.restaurantID, itemStatus;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRMIName
(IN iname varchar(100))
BEGIN
	SELECT r.restaurantID, restaurantName, rm.itemName, itemPrice, itemType, itemCount, itemStatus
		FROM restaurant AS r 
        INNER JOIN restaurant_menu AS rm ON r.restaurantID = rm.restaurantID
        INNER JOIN menu_items AS mi ON rm.itemName = mi.itemName
        WHERE iname = rm.itemName
        ORDER BY r.restaurantID, itemStatus;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRMICnt
(IN icount int)
BEGIN
	SELECT r.restaurantID, restaurantName, rm.itemName, itemPrice, itemType, itemCount, itemStatus
		FROM restaurant AS r 
        INNER JOIN restaurant_menu AS rm ON r.restaurantID = rm.restaurantID
        INNER JOIN menu_items AS mi ON rm.itemName = mi.itemName
        WHERE icount = itemCount
        ORDER BY r.restaurantID, itemStatus;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRMStatus
(IN istatus varchar(100))
BEGIN
	SELECT r.restaurantID, restaurantName, rm.itemName, itemPrice, itemType, itemCount, itemStatus
		FROM restaurant AS r 
        INNER JOIN restaurant_menu AS rm ON r.restaurantID = rm.restaurantID
        INNER JOIN menu_items AS mi ON rm.itemName = mi.itemName
        WHERE itemStatus LIKE istatus
        ORDER BY r.restaurantID, itemStatus;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE SearchRMType
(IN itype varchar(100))
BEGIN
	SELECT r.restaurantID, restaurantName, rm.itemName, itemPrice, itemType, itemCount, itemStatus
		FROM restaurant AS r 
        INNER JOIN restaurant_menu AS rm ON r.restaurantID = rm.restaurantID
        INNER JOIN menu_items AS mi ON rm.itemName = mi.itemName
        WHERE itemType LIKE itype
        ORDER BY r.restaurantID, itemStatus;
END //
DELIMITER ;