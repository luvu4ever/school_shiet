CREATE TABLE employee(
	emp_id INT PRIMARY KEY,
    first_name VARCHAR(40),
    last_name VARCHAR(40),
    birth_date DATE,
    sex VARCHAR(1),
    salary INT
);

alter table employee
drop foreign key employee_ibfk_1;

alter table employee
drop branch_id;

show create table employee;



CREATE TABLE branch(
	branch_id INT PRIMARY KEY,
    branch_name VARCHAR(40),
    mgr_id INT,
    mgr_start_data DATE,
    FOREIGN KEY(mgr_id) REFERENCES employee(emp_id) ON DELETE SET NULL
);

ALTER TABLE employee
add branch_id INT default 0;

ALTER TABLE employee
ADD foreign key (branch_id)
REFERENCES branch(branch_id) 
ON DELETE SET NULL;

ALTER TABLE employee
add foreign key (super_id)
references employee(emp_id)
on delete set null;

create table client(
	client_id INT Primary key,
    client_name varchar(40),
    branch_id INT,
    foreign key (branch_id) references branch(branch_id) on delete set null
);

create table works_with(
	emp_id INT,
    client_id INT,
    total_sales INT,
    Primary key(emp_id, client_id),
    foreign key(emp_id) references employee(emp_id) on delete cascade,
    foreign key(client_id) references client(client_id) on delete cascade
);

alter table works_with
add foreign key(emp_id)
references employee(emp_id)
on delete cascade;

create table branch_supplier(
	branch_id INT,
    supplier_name VARCHAR(40),
    supply_type VARCHAR(40),
    primary key(branch_id, supplier_name),
    foreign key(branch_id) references branch(branch_id) on delete cascade
);
