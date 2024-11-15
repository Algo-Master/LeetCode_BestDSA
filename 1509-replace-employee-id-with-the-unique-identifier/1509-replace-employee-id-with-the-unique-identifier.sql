# Write your MySQL query statement below
SELECT EmployeeUNI.unique_id, name
FROM Employees
LEFT JOIN EmployeeUNI
on Employees.id = EmployeeUNI.id