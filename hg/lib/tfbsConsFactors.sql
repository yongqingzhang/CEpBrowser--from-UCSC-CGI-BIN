# tfbsConsFactors.sql was originally generated by the autoSql program, which also 
# generated tfbsConsFactors.c and tfbsConsFactors.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#tfbsConsFactors Data
CREATE TABLE tfbsConsFactors (
    name varchar(255) not null,	# Name of item
    ac varchar(255) not null,	# gene-regulation.com AC
    species char(6) not null,	# common name, scientific name
    factor char(64) not null,	# factor 
    id char(25) not null,	# id
              #Indices
    INDEX(name(10))
);