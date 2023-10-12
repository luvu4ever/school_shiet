SELECT DUAN.MADUAN, DUAN.TENDUAN, 
		TIMESTAMPDIFF(month, DUAN.TGBD, DUAN.TGKT) as SOTHANGTHUCHIEN,
        COUNT(DISTINCT PHANCONG.MANV) AS SONHANVIEN,
        SUM(SONGAYCONG) AS TONGSONGAYCONG
from DUAN
JOIN PHANCONG ON DUAN.MADUAN = PHANCONG.MADUAN
GROUP BY DUAN.MADUAN, DUAN.TENDUAN;

SELECT NHANVIEN.MANV, NHANVIEN.HOTENNV, CHUCVU.TENCHUCVU,
		SUM(LITTLE.LUONGTB * LITTLE.TONGSONGAYCONG) AS TONGLUONG
        FROM(
			SELECT NHANVIEN.MANV AS MANV, SUM(PHANCONG.SONGAYCONG) AS TONGSONGAYCONG, CHUCVU.LUONGCB AS LUONGTB, CHUCVU.TENCHUCVU AS TENCHUCVU
			FROM PHANCONG
			JOIN NHANVIEN ON NHANVIEN.MANV = PHANCONG.MANV
			JOIN DUAN ON PHANCONG.MADUAN = DUAN.MADUAN AND DUAN.TGBD >= '2017-01-01'
            JOIN CHUCVU ON NHANVIEN.MACHUCVU = CHUCVU.MACHUCVU
			GROUP BY PHANCONG.MANV
        ) LITTLE
        JOIN NHANVIEN ON LITTLE.MANV = NHANVIEN.MANV
        JOIN CHUCVU ON NHANVIEN.MACHUCVU = CHUCVU.MACHUCVU
        GROUP BY NHANVIEN.MANV;

SELECT NHANVIEN.MANV, SUM(PHANCONG.SONGAYCONG), CHUCVU.LUONGCB
FROM PHANCONG
JOIN NHANVIEN ON NHANVIEN.MANV = PHANCONG.MANV
JOIN DUAN ON PHANCONG.MADUAN = DUAN.MADUAN AND DUAN.TGBD >= '2017-01-01'
JOIN CHUCVU ON NHANVIEN.MACHUCVU = CHUCVU.MACHUCVU
GROUP BY PHANCONG.MANV;

(select MADUAN, TENDUAN
FROM DUAN
ORDER BY TIMESTAMPDIFF(DAY, TGBD, TGKT) desc
LIMIT 1)
UNION
(select DUAN.MADUAN, DUAN.TENDUAN
FROM DUAN
JOIN PHANCONG ON DUAN.MADUAN = PHANCONG.MADUAN
GROUP BY DUAN.MADUAN
ORDER BY COUNT(DISTINCT PHANCONG.MANV) DESC
LIMIT 1);

CREATE TRIGGER CHECKDUAN
ON DUAN
FOR INSERT
AS
BEGIN
    IF EXISTS (SELECT * FROM inserted WHERE YEAR(NGAYBD) >= 2001)
    BEGIN
        RAISERROR('Ngày sinh phải trước năm 2001.', 16, 1);
        ROLLBACK;
    END
END;
