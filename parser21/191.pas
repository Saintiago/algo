PROGRAM AverageScore(INPUT, OUTPUT);
CONST
  NumberOfScores = 4;
  ClassSize = 4;
TYPE	
  Score = 0 .. 100;
VAR
  WhichScore: 1 .. NumberOfScores;
  Student: 1 .. ClassSize;
  NextScore: Score;
  Ave, TotalScore, ClassTotal: INTEGER;
BEGIN {AverageScore}
  ClassTotal := 0;
  WRITELN('Student averages:');
  FOR Student := 1 TO ClassSize
  DO 
    BEGIN
      TotalScore := 0;
      FOR WhichScore := 1 TO NumberOfScores
      DO
        BEGIN
          READ(NextScore);
          TotalScore := TotalScore + NextScore;
        END;
      READLN;
      TotalScore := TotalScore * 10;
      Ave := TotalScore DIV NumberOfScores;
      WRITE('Current average: ');
      IF Ave MOD 10 >= 5
      THEN
        WRITE(Ave DIV 10 + 1)
      ELSE
        WRITE(Ave DIV 10);
      WRITELN;  
      ClassTotal := ClassTOtal + TotalScore;
    END;
  WRITELN;
  WRITELN ('Class average:');
  ClassTotal := ClassTotal DIV (ClassSize * NumberOfScores);
  WRITELN(ClassTotal DIV 10, '.', ClassTotal MOD 10:1)
END.  {AverageScore}

