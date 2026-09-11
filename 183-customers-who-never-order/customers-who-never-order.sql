# Write your MySQL query statement below
SELECT name as Customers
from Customers c1 
Left outer join Orders o1
on c1.id=o1.customerID 
where o1.id is null