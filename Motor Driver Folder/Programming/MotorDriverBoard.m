classdef MotorDriverBoard
    %UNTITLED2 Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        AIN1=0;
        AIN2 = 0;
        BIN1 = 0;
        BIN2 = 0;
        nFault = 0;
        nSleep = 0;
    end
    
    methods
        function MDB=FullForward(MDB,motor)
            if(motor==1 || motor==3)
                MDB.AIN1 = 1;
                MDB.AIN2 = 0;
            end
            if(motor==2|| motor==3)
                MDB.BIN1 = 1;
                MDB.BIN2 = 0;
            end
        end
        function MDB=FullReverse(MDB,motor)
            if(motor==1 || motor==3)
                MDB.AIN1 = 0;
                MDB.AIN2 = 1;
            end
            if(motor==2|| motor==3)
                MDB.BIN1 = 0;
                MDB.BIN2 = 1;
            end
        end
        function MDB=SpeedForward(MDB,motor,speed)
            if(motor==1 || motor==3)
                MDB.AIN1 = 1;
                MDB.AIN2 = 1-speed;
            end
            if(motor==2|| motor==3)
                MDB.BIN1 = 1;
                MDB.BIN2 = 1-speed;
            end
        end
        function MDB=SpeedReverse(MDB,motor,speed)
            if(motor==1 || motor==3)
                MDB.AIN1 = 0;
                MDB.AIN2 = 1-speed;
            end
            if(motor==2|| motor==3)
                MDB.BIN1 = 0;
                MDB.BIN2 = 1-speed;
            end
        end
        %function TurnByAngle(angle,direction)
        %    
        %end
        function MDB=Stop(MDB)
            MDB.AIN1 = 1;
            MDB.AIN2 = 1;
            MDB.BIN1 = 1;
            MDB.BIN2 = 1;
        end
    end
    
    
end



