#include <iostream>
#include <cassert>
#include "sql_query_builder.h"
#include <pqxx/pqxx>


int main()
{
/*    try
    {
        std::string connectionString =
            "host=localhost "
            "port=5432 "
            "dbname=dvdrental "
            "user=postgres "
            "password=1331331";


        pqxx::connecting conn(connectionString);
    }

    catch (const std::exception& e)
    {
        std::cout << "Error:" << e.what();
    }
*/
    SqlSelectQueryBuilder query_builder;


    query_builder.AddColumns({ "name", "phone", "email" });

    query_builder.AddFrom("students");

    std::map<std::string, std::string> value = { {"id", "1"}, {"name", "John"}, {"age", "73"} };
    query_builder.AddWhere2(value);

    const std::string result = query_builder.BuildQuery();
    std::cout << result << std::endl;

    return 0;
 /*
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    assert(query_builder.BuildQuery() == 
        "SELECT name, phone FROM students WHERE id=42 AND name=John;");

    SqlSelectQueryBuilder query_builder2;
    query_builder2.AddFrom("students");
    query_builder2.AddWhere("id", "42");
    assert(query_builder2.BuildQuery() == "SELECT * FROM students WHERE id=42;");

    SqlSelectQueryBuilder query_builder3;
    query_builder3.AddColumn("name");
    query_builder3.AddFrom("students");
    assert(query_builder3.BuildQuery() == "SELECT name FROM students;");

    SqlSelectQueryBuilder query_builder4;
    std::map<std::string, std::string> where_conditions = { {"city", "New York"}, {"country", "USA"} };
    query_builder4.AddFrom("users").AddWhere2(where_conditions);
    assert(query_builder4.BuildQuery() == "SELECT * FROM users WHERE city=New York AND country=USA;");

    SqlSelectQueryBuilder query_builder5;
    std::vector<std::string> columns = { "id", "username", "email" };
    query_builder5.AddColumns(columns).AddFrom("users");
    assert(query_builder5.BuildQuery() == "SELECT id, username, email FROM users;");


    SqlSelectQueryBuilder query_builder6;
    std::vector<std::string> empty_columns;
    query_builder6.AddColumns(empty_columns).AddFrom("users");
    assert(query_builder6.BuildQuery() == "SELECT * FROM users;");

    return 0;*/
}