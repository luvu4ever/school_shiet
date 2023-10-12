insert into branch values (4, 'Buffalo', NULL, NULL);

SELECT branch.branch_id, employee.emp_id, employee.first_name, branch.branch_name
FROM employee
right JOIN branch
ON employee.emp_id = branch.mgr_id;

select employee.*, branch.branch_name
from branch
left join employee
on employee.branch_id = branch.branch_id;