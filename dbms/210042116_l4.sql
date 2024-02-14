SET SERVEROUTPUT ON;

-- Task 1
BEGIN
DBMS_output.Put_line('Rakin Shahriar');
END
/

-- Task 2
BEGIN
ID = '&id';
DBMS_output.Put_line('length is : ' || length(ID));
END     

-- Task 3 (a)
DECLARE
    CURSOR lab_3_C1 IS
        SELECT I.ID, I.NAME, I.SALARY, SUM(C.CREDITS) AS TOTAL_CREDITS
        FROM INSTRUCTOR I
        JOIN teaches T ON T.ID = I.ID
        JOIN course C ON C.COURSE_ID = T.COURSE_ID
        GROUP BY I.ID, I.NAME, I.SALARY;
    
    NEW_SALARY INSTRUCTOR.SALARY%TYPE;

BEGIN
    FOR REC IN lab_3_C1 LOOP
        NEW_SALARY := 9000 * REC.TOTAL_CREDITS;
        IF NEW_SALARY != REC.SALARY THEN
                UPDATE INSTRUCTOR
                SET SALARY = CASE
                WHEN NEW_SALARY<=29000 THEN 30000
                ELSE NEW_SALARY 
                END
                WHERE ID = REC.ID;
        ELSE    
            DBMS_OUTPUT.PUT_LINE(REC.NAME );
        END IF;
    END LOOP;

    COMMIT;
END;
/


-- TASK 3 (B)
DECLARE
    CURSOR lab_3_C2 IS
        SELECT C.TITLE, S.NAME
        FROM COURSE c
        JOIN prereq P ON C.COURSE_ID = P.COURSE_ID
        JOIN TAKES T ON P.prereq_id = T.COURSE_ID
        JOIN STUDENT S ON T.ID = S.ID;

BEGIN
    FOR REC IN lab_3_C2 LOOP
        DBMS_OUTPUT.PUT_LINE('Course Title: ' || rec.title || ', Student Name: ' || rec.name);
    END LOOP;
END;
/


-- task 4 (c)
DECLARE 
    student_name student.name%TYPE := &student_name;
    CURSOR c1 IS
        SELECT ts.day, ts.start_hr || ':' || ts.start_min as start_time, 
               ts.end_hr || ':' || ts.end_min as end_time, 
               s.course_id, c.title, s.building, s.room_number
        FROM student st
        JOIN takes t ON st.ID = t.ID
        JOIN section s ON t.course_id = s.course_id AND t.sec_id = s.sec_id
        JOIN time_slot ts ON s.time_slot_id = ts.time_slot_id
        JOIN course c ON s.course_id = c.course_id
        WHERE st.name = student_name
        ORDER BY 
            CASE ts.day
                WHEN 'M' THEN 1
                WHEN 'T' THEN 2
                WHEN 'W' THEN 3
                WHEN 'Th' THEN 4
                WHEN 'F' THEN 5
                WHEN 'S' THEN 6
                WHEN 'Su' THEN 7
            END,
            ts.start_hr,
            ts.start_min;

BEGIN
    FOR rec IN c1 LOOP
        DBMS_OUTPUT.PUT_LINE('<' || rec.day || '>');
        DBMS_OUTPUT.PUT_LINE('<' || rec.start_time || ' - ' || rec.end_time || '>');
        DBMS_OUTPUT.PUT_LINE('<' || rec.course_id || ' - ' || rec.title || '>');
        DBMS_OUTPUT.PUT_LINE('<' || rec.building || ' - ' || rec.room_number || '>');
        DBMS_OUTPUT.PUT_LINE(' ');
    END LOOP;
END;
/



-- TASK 3 (D)
DECLARE
    CURSOR lab_3_C4 IS
        SELECT I.ID, I.NAME, I.dept_name
        FROM INSTRUCTOR i
        LEFT JOIN ADVISOR A ON I.ID = A.i_ID
        WHERE A.I_ID IS NULL;

    STUDENT_ID STUDENT.ID%TYPE;

BEGIN
    FOR REC IN lab_3_C4 LOOP
        SELECT ID INTO STUDENT_ID
        FROM STUDENT
        WHERE DEPT_NAME = REC.DEPT_NAME AND ID NOT IN (SELECT S_ID FROM ADVISOR) AND ROWNUM = 1
        ORDER BY tot_cred ASC;
        

        IF STUDENT_ID IS NOT NULL THEN
            INSERT INTO ADVISOR (S_ID, I_ID) VALUES (STUDENT_ID, REC.ID);
        ELSE
            DBMS_OUTPUT.PUT_LINE('NO STUDENTS ASSIGNED TO : ' || REC.NAME);
        END IF;
    END LOOP;

    COMMIT;

EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('NO STUDENT AVAILABLE');

END;
/



-- TASK 3 (E)
DECLARE 
    dept_name department.dept_name%TYPE;
    min_id instructor.ID%TYPE;
    avg_salary instructor.salary%TYPE;
    new_id instructor.ID%TYPE;
    new_instructor instructor%ROWTYPE;
BEGIN
    SELECT dept_name INTO dept_name
    FROM student
    GROUP BY dept_name
    ORDER BY COUNT(*) DESC
    FETCH FIRST ROW ONLY;

    SELECT MIN(ID) INTO min_id FROM instructor;

    SELECT AVG(salary) INTO avg_salary FROM instructor WHERE dept_name = dept_name;

    new_id := TO_CHAR(TO_NUMBER(min_id) - 1);

    INSERT INTO instructor (ID, name, dept_name, salary)
    VALUES (new_id, 'John Doe', dept_name, avg_salary);

    SELECT * INTO new_instructor FROM instructor WHERE ID = new_id;

    DBMS_OUTPUT.PUT_LINE('Instructor Information:');
    DBMS_OUTPUT.PUT_LINE('ID: ' || new_instructor.ID);
    DBMS_OUTPUT.PUT_LINE('Name: ' || new_instructor.name);
    DBMS_OUTPUT.PUT_LINE('Department Name: ' || new_instructor.dept_name);
    DBMS_OUTPUT.PUT_LINE('Salary: ' || new_instructor.salary);

    COMMIT;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No data found.');
    WHEN DUP_VAL_ON_INDEX THEN
        DBMS_OUTPUT.PUT_LINE('Duplicate value on index.');
END;
/