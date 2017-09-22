#------------------------------------------------------------
#        Script MySQL.
#------------------------------------------------------------


#------------------------------------------------------------
# Table: Departement
#------------------------------------------------------------

CREATE TABLE Departement(
        Iddepartement  int (11) Auto_increment  NOT NULL ,
        Numdepartement Int NOT NULL ,
        Nomdepartement Varchar (40) ,
        PRIMARY KEY (Iddepartement )
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Ville
#------------------------------------------------------------

CREATE TABLE Ville(
        Idville       int (11) Auto_increment  NOT NULL ,
        Nomville      Varchar (50) NOT NULL ,
        Iddepartement Int ,
        PRIMARY KEY (Idville )
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Codepostal
#------------------------------------------------------------

CREATE TABLE Codepostal(
        Idcodepostal  int (11) Auto_increment  NOT NULL ,
        Numcodepostal Int NOT NULL ,
        PRIMARY KEY (Idcodepostal )
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Ligne
#------------------------------------------------------------

CREATE TABLE Ligne(
        Idligne   int (11) Auto_increment  NOT NULL ,
        Codeligne Int NOT NULL ,
        PRIMARY KEY (Idligne )
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Gare
#------------------------------------------------------------

CREATE TABLE Gare(
        Idgare       int (11) Auto_increment  NOT NULL ,
        Nomgare      Varchar (50) NOT NULL ,
        Idville      Int NOT NULL ,
        Idcodepostal Int ,
        PRIMARY KEY (Idgare )
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Naturedesserte
#------------------------------------------------------------

CREATE TABLE Naturedesserte(
        Iddesserte     int (11) Auto_increment  NOT NULL ,
        Naturedesserte Varchar (50) NOT NULL ,
        PRIMARY KEY (Iddesserte )
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Ville_Posseder_Codepostal
#------------------------------------------------------------

CREATE TABLE Ville_Posseder_Codepostal(
        Idville      Int NOT NULL ,
        Idcodepostal Int NOT NULL ,
        PRIMARY KEY (Idville ,Idcodepostal )
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Ligne_dessert_gare_naturedesserte
#------------------------------------------------------------

CREATE TABLE Ligne_dessert_gare_naturedesserte(
        WGS84           Varchar (25) NOT NULL ,
        Latitude_wgs84  Float NOT NULL ,
        Longitude_wgs84 Float NOT NULL ,
        Idgare          Int NOT NULL ,
        Idligne         Int NOT NULL ,
        Iddesserte      Int NOT NULL ,
        PRIMARY KEY (Idgare ,Idligne ,Iddesserte )
)ENGINE=InnoDB;

ALTER TABLE Ville ADD CONSTRAINT FK_Ville_Iddepartement FOREIGN KEY (Iddepartement) REFERENCES Departement(Iddepartement);
ALTER TABLE Gare ADD CONSTRAINT FK_Gare_Idville FOREIGN KEY (Idville) REFERENCES Ville(Idville);
ALTER TABLE Gare ADD CONSTRAINT FK_Gare_Idcodepostal FOREIGN KEY (Idcodepostal) REFERENCES Codepostal(Idcodepostal);
ALTER TABLE Ville_Posseder_Codepostal ADD CONSTRAINT FK_Ville_Posseder_Codepostal_Idville FOREIGN KEY (Idville) REFERENCES Ville(Idville);
ALTER TABLE Ville_Posseder_Codepostal ADD CONSTRAINT FK_Ville_Posseder_Codepostal_Idcodepostal FOREIGN KEY (Idcodepostal) REFERENCES Codepostal(Idcodepostal);
ALTER TABLE Ligne_dessert_gare_naturedesserte ADD CONSTRAINT FK_Ligne_dessert_gare_naturedesserte_Idgare FOREIGN KEY (Idgare) REFERENCES Gare(Idgare);
ALTER TABLE Ligne_dessert_gare_naturedesserte ADD CONSTRAINT FK_Ligne_dessert_gare_naturedesserte_Idligne FOREIGN KEY (Idligne) REFERENCES Ligne(Idligne);
ALTER TABLE Ligne_dessert_gare_naturedesserte ADD CONSTRAINT FK_Ligne_dessert_gare_naturedesserte_Iddesserte FOREIGN KEY (Iddesserte) REFERENCES Naturedesserte(Iddesserte);
