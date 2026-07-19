# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE Salary <(Select MAX(Salary) FROM Employee);