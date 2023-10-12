select employee.emp_id, employee.first_name, employee.last_name
from employee
where employee.emp_id IN(
select distinct works_with.emp_id
from works_with
where works_with.total_sales > 30000
);

select client.client_name, client.branch_id
from client
where client.branch_id =(
	select branch.branch_id
	from branch
	where branch.mgr_id = 102
    LImit 1)
;