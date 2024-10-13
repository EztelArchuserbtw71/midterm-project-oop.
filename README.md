# midterm-project-oop.
A inventory management system
Validations:
1st is when inventory is empty you cannot Update Item, Remove Item, Display Items by Category,Display All Items, Search Item, Sort Items, Display Low Stock Items, and even Sort Items.
2nd the Item Category Validation:
 When adding a Item is to Input first the Category either choose one of this 3 (Clothing, Electronics, and Entertainment)before product id, price and quantity.
   - If the user inputs are numerical or alphabetical invalid category, an error message is displayed9actually there is different error message.

3rd Item ID Validation:
When adding an item, the user is needed to enter an ID. There are no explicit checks for duplicated IDs, but the absence of item with a given ID is checked when updating or removing an item.

4rth Quantity and Price Validations:
   - When updating an item, the user must specify a valid field:
   - Id(what id need to be update or remove there will be a records will show) 
     - Quantity
     - Price
   - If the user enters an invalid field, an error message is displayed and will return to menu.
   - A check is made to ensure the quantity entered for the item is valid before updating like <name> has been updated!.

5th Item Search Validation:
   - When searching for an item ID is only needed but there will be no record shown to pick what id just find it your self, a message is displayed if the item is not found.
   - if found it will be shown by name,category,price, and quantity.

6th Display Items Validation:
   - When displaying items by category, a message is displayed if no items are found in that category it will back to menu, if its along with suggested categories that contain items it will shown.

7th Low Stock Items Validation:
   - When displaying low stock items, there will be specified limit of 5 quantity, a message will displayed no low stocks.

8th Sorting Items Validation:
   - When sorting items, if no items are present in the inventory it will reurn menu and leave a message, an appropriate message is displayed before attempting to sort. like price or quantity first and then lowest and highest as my ascending and descending

