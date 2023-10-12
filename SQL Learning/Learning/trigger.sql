CREATE TABLE trigger_test (
     message VARCHAR(100)
);

delimeter $$
create trigger my_trigger before insert
on employee
for each row begin 
	insert into trigger_test values ('added new employee');
end$$
delimeter ;