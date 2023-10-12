CREATE TABLE KH(
	MKH varchar(5),
	TenKH nvarchar(50),
	DT varchar(20),
	DC varchar(200),
	Email varchar(50),
	MST varchar(20),
	CONSTRAINT pk_KH PRIMARY KEY (MKH)
);

CREATE TABLE DH(
	MDH varchar(5),
	MKH varchar(5),
	NgayMua DateTime,
	CONSTRAINT pk_DH PRIMARY KEY (MDH),
	CONSTRAINT fk_DH FOREIGN KEY (MKH) REFERENCES KH(MKH)
);

CREATE TABLE TheLoai(
	TL nvarchar(20),
	CONSTRAINT pk_TL PRIMARY KEY (TL)
);

CREATE TABLE Sach(
	MS varchar(5),
	TenS varchar(50),
	Nam int, 
	Gia int,
	TheLoai nvarchar(20),
	SoLuong int,
	CONSTRAINT pk_Sach PRIMARY KEY (MS),
	CONSTRAINT fr_TLS FOREIGN KEY (TheLoai) REFERENCES TheLoai(TL)
);

CREATE TABLE DH_chitiet(
	MDH varchar(5),
	MS varchar(5),
	SoLuong int,
	CONSTRAINT fk_DH_MDH FOREIGN KEY (MDH) REFERENCES DH(MDH),
	CONSTRAINT fk_DH_MS FOREIGN KEY(MS) REFERENCES Sach(MS)
);

-- Insert data into the KH table (Customers)
INSERT INTO KH (MKH, TenKH, DT, DC, Email, MST)
VALUES
('KH001', N'John Smith', '0123456789', N'New York', 'johnsmith@gmail.com', 'MST001'),
('KH002', N'Emma Johnson', '0987654321', N'Los Angeles', 'emmajohnson@gmail.com', 'MST002'),
('KH003', N'Michael Brown', '0123456789', N'Chicago', 'michaelbrown@gmail.com', 'MST003'),
('KH004', N'Olivia Davis', '0987654321', N'Houston', 'oliviadavis@gmail.com', 'MST004'),
('KH005', N'William Miller', '0123456789', N'Phoenix', 'williammiller@gmail.com', 'MST005'),
('KH006', N'Sophia Wilson', '0987654321', N'San Francisco', 'sophiawilson@gmail.com', 'MST006'),
('KH007', N'James Taylor', '0123456789', N'Seattle', 'jamestaylor@gmail.com', 'MST007'),
('KH008', N'Isabella Thomas', '0987654321', N'Dallas', 'isabellathomas@gmail.com', 'MST008'),
('KH009', N'Joseph Martinez', '0123456789', N'Miami', 'josephmartinez@gmail.com', 'MST009'),
('KH010', N'Sophia Anderson', '0987654321', N'Atlanta', 'sophiaanderson@gmail.com', 'MST010');

-- Insert data into the DH table (Orders)
INSERT INTO DH (MDH, MKH, NgayMua)
VALUES
('DH001', 'KH001', '2023-05-01'),
('DH002', 'KH002', '2023-05-02'),
('DH003', 'KH003', '2023-05-03'),
('DH004', 'KH004', '2023-05-04'),
('DH005', 'KH005', '2023-05-05'),
('DH006', 'KH006', '2023-05-06'),
('DH007', 'KH007', '2023-05-07'),
('DH008', 'KH008', '2023-05-08'),
('DH009', 'KH009', '2023-05-09'),
('DH010', 'KH010', '2023-05-10');

-- Insert data into the TheLoai table (Categories)
INSERT INTO TheLoai (TL)
VALUES
('Children'),
('Textbook'),
('Economics'),
('Engineering'),
('Psychology'),
('Fiction'),
('History'),
('Science'),
('Art'),
('Sports');

-- Insert data into the Sach table (Books)
INSERT INTO Sach (MS, TenS, Nam, Gia, TheLoai, SoLuong)
VALUES
('S001', N'Book A', 2021, 100000, 'Children', 50),
('S002', N'Book B', 2022, 150000, 'Textbook', 30),
('S003', N'Book C', 2020, 200000, 'Economics', 20),
('S004', N'Book D', 2019, 180000, 'Engineering', 15),
('S005', N'Book E', 2023, 120000, 'Psychology', 10),
('S006', N'Book F', 2022, 135000, 'Fiction', 25),
('S007', N'Book G', 2018, 220000, 'History', 12),
('S008', N'Book H', 2023, 175000, 'Science', 18),
('S009', N'Book I', 2020, 190000, 'Art', 20),
('S010', N'Book J', 2021, 125000, 'Sports', 15);

-- Insert data into the DH_chitiet table (Order Details)
INSERT INTO DH_chitiet (MDH, MS, SoLuong)
VALUES
('DH001', 'S001', 2),
('DH001', 'S002', 1),
('DH002', 'S003', 3),
('DH002', 'S004', 2),
('DH002', 'S005', 1),
('DH003', 'S006', 2),
('DH003', 'S007', 1),
('DH004', 'S008', 3),
('DH004', 'S009', 2),
('DH004', 'S010', 1);

-- 1. Đưa ra thông tin chi tiết đơn hãng mã '1221', dữ liệu random nên chọn 'DH002'
SELECT kh.TenKH, s.MS, s.TenS, s.Gia, s.Nam, s.TheLoai, ct.SoLuong 
FROM DH_chitiet ct, DH dh, Sach s, KH kh
WHERE s.MS = ct.MS AND dh.MDH = ct.MDH AND dh.MDH = 'DH002' AND kh.MKH = dh.MKH;

SELECT kh.TenKH, s.MS, s.TenS, s.Gia, s.Nam, s.TheLoai, ct.SoLuong
from DH_chitiet as ct, DH as dh, Sach as s, KH as kh
where s.MS = ct.MS and dh.MDH = ct.MDH and dh.MDH = 'DH002' and kh.MKH = dh.MKH;

select * from DH_chitiet;

select s.MS, s.TenS, ct.SoLuong
from DH_chitiet as ct
Join Sach as s on s.MS = ct.MS
where ct.SoLuong = (Select MAX(total_sold) from (Select Sum(SoLuong) as total_sold from DH_chitiet group by MS));

select total.MS, s.TenS, total.total_sold
from(
	select MS, SUM(SoLuong) as total_sold
    from DH_chitiet as ct
    group by MS
) as total
join Sach as s on total.MS = s.MS
where total_sold = (Select MAX(total_sold) from (select SUM(SoLuong) as total_sold from DH_chitiet group by MS) as total);



SELECT MS, total_sold
FROM (
    SELECT MS, SUM(SoLuong) AS total_sold
    FROM DH_chitiet
    GROUP BY MS
) AS book_sales
WHERE total_sold = (SELECT MAX(total_sold) FROM (SELECT SUM(SoLuong) AS total_sold FROM DH_chitiet GROUP BY MS) AS book_sales);

SELECT *
FROM DH_chitiet
WHERE MDH = 'DH002';

-- 2. Thể loại thâm lý có bao nhiêu đầu sách

-- 3. Cho biết tổng giá trị tất cả các đơn hàng trong ngày 26/5/2023, thay thành 2023-05-03
-- cách 1
SELECT SUM(s.Gia*ct.SoLuong) AS SUM FROM Sach s, DH_chitiet ct, DH dh
WHERE s.MS = ct.MS AND ct.MDH = dh.MDH AND dh.NgayMua = '2023-05-03';

SELECT SUM(s.Gia*ct.SoLuong) AS SUM 
FROM Sach as s 
JOIN DH_chitiet as ct ON s.MS = ct.MS 
JOIN DH dh ON ct.MDH = dh.MDH 
WHERE dh.NgayMua = '2023-05-03';


CREATE VIEW view1 AS
SELECT s.MS, s.TenS, SUM(ct.SoLuong) AS SoLuong
FROM Sach s
JOIN DH_chitiet ct ON ct.MS = s.MS
JOIN DH dh ON dh.MDH = ct.MDH
WHERE dh.NgayMua = '2023-05-03'
GROUP BY s.MS, s.TenS;

create view view2 as
Select s.MS, s.TenS, sum(ct.SoLuong) as SoLuong
from Sach as s
join DH_chitiet ct on ct.MS = s.MS
join DH as dh on dh.MDH = ct.MDH
where dh.NgayMua = '2023-05-03'
group by s.MS, s.TenS;

SELECT * FROM view1;

	UPDATE Sach
	SET Gia = Gia / 1.05;
    
    
select * from Sach;

create Procedure Update_gia 
	@MaS varchar(5)
as
begin
	Update Sach
    set Gia = Gia * 1.05
    where MS = @MaS
end;

CREATE PROC pPROC
@MS varchar(5)
AS
BEGIN
	SELECT SUM(ct.SoLuong) AS [Số lượng đã bán], SUM(s.SoLuong) AS [Số lượng còn lại] 
	FROM DH_chitiet ct JOIN Sach s ON ct.MS = s.MS
	WHERE s.MS = @MS
END

--'2023-05-03' là để thử theo yêu cầu đề bài thì thay bằng GETDATE()

--5. Giá cả các cuốn sách tăng 5%. Cập nhật thông tin
SELECT * FROM Sach

UPDATE Sach
SET Gia = Gia * 1.05;

SELECT * FROM Sach


--Đề 1
--1. Đưa ra thông tin những quyển sách mà số lượng còn lại nhỏ hơn 10 cuốn

--Update để có kết quả thôi !
UPDATE Sach
SET SoLuong = SoLuong - 1
WHERE MS =  'S005'
------------------------------

SELECT * FROM Sach WHERE Sach.SoLuong < 10

--2. Cho biết An Nam' đã bán đư sách có tên 'Tâm lý dân tộcợc bao nhiêu quyển ?
-- Đổi thành tên 'Book I'
--update để check

SELECT SUM(ct.SoLuong) AS [Số lượng đã bán]
FROM DH_chitiet ct 
JOIN Sach s ON ct.MS = s.MS 
WHERE s.TenS = N'Book I' 

--3. Tổng giá trị các đơn hàng mà khách có mã 'KH002' đã mua từ trước đến ngày hiện tại
SELECT SUM(ct.SoLuong*s.Gia) AS [Tổng giá trị] FROM DH_chitiet ct 
JOIN DH dh ON ct.MDH = dh.MDH
JOIN Sach s ON s.MS = ct.MS
WHERE dh.MKH = 'KH002' AND dh.NgayMua <= GETDATE()

--4. Tạo thủ tục lưu trữ nhận tham số đầu vào là mã sách, hiển thị thông tin số lượng cuốn sách đã bán, và số lượng còn lại trong cửa hàng
CREATE PROC pPROC
@MS varchar(5)
AS
BEGIN
	SELECT SUM(ct.SoLuong) AS [Số lượng đã bán], SUM(s.SoLuong) AS [Số lượng còn lại] 
	FROM DH_chitiet ct JOIN Sach s ON ct.MS = s.MS
	WHERE s.MS = @MS
END

EXEC pPROC 'S002'

--5. Xoá toàn bộ thông tin liên quan đến các đơn hàng '5/3/2023'

-- xem có những cái nào
SELECT * FROM DH_chitiet WHERE MDH 
IN(SELECT MDH FROM DH WHERE CONVERT(DateTime, NgayMua) = '2023-05-03') 

-- xoá
DELETE FROM DH_chitiet WHERE MDH 
IN(SELECT MDH FROM DH WHERE CONVERT(DateTime, NgayMua) = '2023-05-03') 

-- giờ xem lại lệnh trên xem còn không
-- xem trong bảng DH còn thì xoá nốt
SELECT MDH FROM DH WHERE CONVERT(DateTime, NgayMua) = '2023-05-03'
-- xoá ở bảng DH
DELETE FROM DH WHERE CONVERT(DateTime, NgayMua) = '2023-05-03'
-- xem lại xem còn không