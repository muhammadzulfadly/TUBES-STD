# APLIKASI BOOKING TEATER
TUBES Struktur Data : Multi-Linked List M ke N
# Kelompok 14
- Nurul Pratiwi (1302213052)
- Muhammad Zulfadly (1302210046)
# Studi Kasus
<img width="1172" alt="Screenshot 2023-01-01 at 21 12 45" src="https://user-images.githubusercontent.com/121471995/210173966-1b1ec95f-3916-4fc7-8d79-1d987971e456.png">
Pembookingan Teater yang berfungsi untuk mendata Pelanggan yang ingin menonton pertunjukan Teater, dimana Pelanggan bisa membooking kuota lebih dari 1 apabila masih ada kuota  dan juga Teater bisa menentukan kapasitas kuota secara bebas. Kuota Teater akan otomatis berkurang apabila sudah ada yang membooking dan kuota Teater akan otomatis bertambah kembali apabila transaksi dihapus.

# Spesifikasi Umum
- Pelanggan(Parent)
  - ID
  - Nama
  - Usia 
  - Jenis Kelamin
- Teater(Child)
  - Studio
  - Acara
  - Jadwal
  - Kapasitas
- Transaksi(Relasi)
  - Relasi antara list Parent dan list Child
# Fungsionalitas
- Insert data teater dari depan
- Show all data teater
- Menghapus data teater dan data pelanggan 
- Mencari data teater 
- Insert data pelanggan
- Menghubungkan data teater beserta data pelanggan
- Menampilkan data teater yang telah dibooking beserta jumlah pelanggan yang telah membooking
- Mencari data pelanggan yang telah membooking pada teater tertentu
- Menghapus data pelanggan pada teater tertentu
- Menghitung jumlah data pelanggan dari teater tertentu
