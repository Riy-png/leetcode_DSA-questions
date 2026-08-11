WITH cte AS (
    SELECT Id, 
           ROW_NUMBER() OVER(PARTITION BY Email ORDER BY Id) as rn 
    FROM Person
)
DELETE Person 
FROM Person
JOIN cte ON Person.Id = cte.Id
WHERE cte.rn > 1;