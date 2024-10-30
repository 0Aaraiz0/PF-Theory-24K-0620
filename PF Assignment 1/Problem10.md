START 
    
    INPUT num 
    
    SET a = 0 
    
    SET b = 1

    WHILE num > 0
        IF num % 100 = 90
            SET a = a + 9 * b 
            SET num = num / 100
            SET b = b * 10
        ELSE 
            SET a = a + (num % 10) * b 
            SET num = num / 10
            SET b = b * 10
        ENDIF
    END WHILE

    PRINT a
END


![IPO](https://github.com/user-attachments/assets/7f8872f6-9fba-49c5-ae57-337b58dc4f44)
![Flowchart](https://github.com/user-attachments/assets/277ce3b1-3282-4d1b-8da2-c997a634a5d0)

