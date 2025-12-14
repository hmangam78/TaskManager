Usar C++20 con <chrono>

soporte nativo para fecha year_month_day

ejemplo:
    auto hoy = year_month_day(std::chrono::system_clock::now());
    std::cout << "Año: " << hoy.year() << std::endl;