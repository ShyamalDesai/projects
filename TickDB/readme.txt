--------------------------------------------------- 
How to use the program:
---------------------------------------------------

A sample tick file is provided:

The application can start with the following params
./TickDB tick1.txt -Oprint -Oproduct
The last 2 params are optional, but will grealy improve performance.

The program will support the print and product command and will loop to ask the params for the commands.
>>>Enter P for print command, S for Sum of Products and Q for quit 
    The Print Command:
    ------------------
    -The print command needs the symbol, the start timestamp and the end timestamp. 
    -Specifying 0 for end timestamp will print all records from start till end of tick file.
    -If the start timestamp is not found, then an upper bound (next best timestamp) less than the end will be used.
    
    e.g. MSFT 1515599665090110 0

    *****If -Oprint is specified, then the application will cache all field Value pairs for a given timestamp and the performance will improve to NLogN
    
    
    The Sum of Product Command:
    --------------------------
    -The product command needs the symbol, the start timestamp, the end timestamp, field1 and field2.
    -Specifying 0 for end timestamp will print all records from start till end of tick file.
    -If the start timestamp is not found, then an upper bound (next best timestamp) less than the end will be used.
    
    e.g.
    MSFT 1515599665091135 1515599665092185 PRICE SIZE

    *****If -Oproduct is specified, then the application will cache the product of 2 fields requested. Hence the 2nd query will be faster.
    
    
    
//--------------------------------------------------------------------------------------------------------------------
//design
//--------------------------------------------------------------------------------------------------------------------

Every record read from the tick file is saved per symbol.
The DS used is std::map (as we need to use upper bound to find the next best Timestamp during query).
The first look up for a symbol to ID-->TickRecord
The ID is used to index into a vector to read the field-value pairs as a string to speed up the print command.
The TickRecord stores the association of TimeStamp to a hash map of Field/Values.

We also use a HashMap to the key formed by Timestamp + field1 + field2 to the product of field1 and field2 for that timestamp. 
This is used to cache the product per timestamp if -Oproduct is specified.


//--------------------------------------------------------------------------------------------------------------------
//Performance
//--------------------------------------------------------------------------------------------------------------------
The order of growth of printing without -Oprint is O(n^2)
The order of growth of printing with -Oprint is O(NLogN)
The order of growth of product command without -OProduct is O (NlogN)
The order of growth of product command with -OProduct is O (NlogN) but has 1 logn Lookup lesser.




