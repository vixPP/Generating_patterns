#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

class SqlSelectQueryBuilder
{
private:
	std::string columns;
	std::string fromTable;
	std::string whereClause;

public:
	SqlSelectQueryBuilder& AddColumn(const std::string& column)
	{
		if (columns.empty())
		{
			columns = column;
		}
		else
		{
			columns += ", " + column;
		}
		return *this;
	}

	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& cols) noexcept 
	{
		if (cols.empty()) return *this;
		for (size_t i = 0; i < cols.size(); ++i) 
		{
			AddColumn(cols[i]);
		}
		return *this;
	}

	SqlSelectQueryBuilder& AddFrom(const std::string& Table)
	{
		fromTable = Table;
		return *this;
	}

	SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value)
	{
		if (whereClause.empty()) 
		{
			whereClause = column + "=" + value;
		}
		else 
		{
			whereClause += " AND " + column + "=" + value;
		}
		return *this;
	}

	SqlSelectQueryBuilder& AddWhere2(const std::map<std::string, std::string>& kv) noexcept 
	{
		if (kv.empty()) return *this;
		for (const auto& pair : kv) 
		{
			AddWhere(pair.first, pair.second);
		}
		return *this;
	}

	std::string BuildQuery() const 
	{
		std::string query = "SELECT ";
		if (columns.empty()) 
		{
			query += "* ";
		}
		else 
		{
			query += columns + " ";
		}
		query += "FROM ";
	
		if (!whereClause.empty()) 
		{
			query += "WHERE " + whereClause + " ";
		}
		query += ";";
		return query;
	}
};
