import React from 'react';
import { BrowserRouter as Router, Routes, Route, Navigate } from 'react-router-dom';
import "bootstrap/dist/css/bootstrap.min.css";
import "./App.css";
import { AuthProvider } from './AuthContext';
import ProtectedRoute from './ProtectedRoute';
import Home from './components/Home/Home';
import Login from './components/Auth/Login';
import SignUp from './components/Auth/SignUp';
import RFID from './components/RFID'; // Import the RFID component
const App = () => {
  return (
    <Router basename="/Canteen-Management">
      <AuthProvider>
        <Routes>
          <Route 
            path="/" 
            element={
              <ProtectedRoute>
                <Home />
              </ProtectedRoute>
            } 
          />
          <Route path="/signup" element={<SignUp />} />
          <Route path="/login" element={<Login />} />
          <Route path="/rfid" element={<RFID />} /> {/* Add the RFID route */}
          <Route path="*" element={<Navigate to="/" />} />
        </Routes>
      </AuthProvider>
    </Router>
  );
};

export default App;