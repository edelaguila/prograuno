CREATE SCHEMA IF NOT EXISTS `didacticat` DEFAULT CHARACTER SET utf8 ;
USE `didacticat` ;

CREATE TABLE IF NOT EXISTS tbl_clientes (
	cliid INT NOT NULL AUTO_INCREMENT,
	clinombre VARCHAR(60) NOT NULL,
	cliestatus VARCHAR(60) NOT NULL,
	PRIMARY KEY (cliid) )
ENGINE = InnoDB CHARACTER SET = latin1;
CREATE TABLE IF NOT EXISTS tbl_productos (
	proid INT NOT NULL AUTO_INCREMENT,
	pronombre VARCHAR(60) NOT NULL,
    proexistencia FLOAT,
	proestatus VARCHAR(60) NOT NULL,
	PRIMARY KEY (proid) )
ENGINE = InnoDB CHARACTER SET = latin1;
    
 CREATE TABLE IF NOT EXISTS tbl_facturae (
	faceid INT NOT NULL,
    facefechaemi date,
    facefechavec date,
    facetotal float,
    cliid INT NOT NULL,
    PRIMARY KEY(faceid),
    FOREIGN KEY (cliid) REFERENCES tbl_clientes (cliid)  
    ) ENGINE=InnoDB CHARACTER SET = latin1;     
CREATE TABLE IF NOT EXISTS tbl_facturad (
	faceid INT NOT NULL,
    proid INT NOT NULL,
    facdorden INT,
    facdcantidad float,
    facdprecio float,
    PRIMARY KEY(faceid, proid, facdorden),
    FOREIGN KEY (faceid) REFERENCES tbl_facturae (faceid),
    FOREIGN KEY (proid) REFERENCES tbl_productos (proid)
    ) ENGINE=InnoDB CHARACTER SET = latin1;     