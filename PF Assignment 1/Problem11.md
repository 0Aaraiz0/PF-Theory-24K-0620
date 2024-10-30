START
    
    INPUT num1, num2  
    
    SET a = num1      
    
    SET b = num2      

    WHILE b ≠ 0        
        SET c = b     
        SET b = a % b 
        SET a = c      
    END WHILE

    IF a = 1 THEN      
        PRINT "The numbers are coprime."
    ELSE
        PRINT "The numbers are not coprime."
    ENDIF
END





![Flowchart](https://github.com/user-attachments/assets/3d2e8aca-4b42-4b9d-9d15-ce52e14f7cf5)
![IPO](https://github.com/user-attachments/assets/8e4b5651-152f-4ec2-91bd-049bccc0f406)
         
